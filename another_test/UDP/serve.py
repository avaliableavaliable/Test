from socket import *
import struct
# struct用于处理C结构数据

s = socket(AF_INET, SOCK_DGRAM)
# 绑定接口
s.bind(('', 69))
# 用于接收客户端上传文件时的IP地址和端口
client_port = ()

# 下载文件
def download(filename, user):
    socket_down = socket(AF_INET, SOCK_DGRAM)
    # 创建用于下载文件的套接字,AF_INET用于Internet进程间通信,SOCK_DREAM数据报套接字，用于UDP协议
    num = 1
    # num表示数据包的序号
    flag = True
    # 定义客户端退出的标签

    # 打开客户端要下载的文件
    try:
        f = open(filename, 'rb')
    except:
        error_data = struct.pack("!HH5sb", 5, 5, 'error'.encode('utf-8'), 0)
        socket_down.sendto(error_data, user)
        # 文件不存在时发送,注意元组
        print("文件不存在")
        flag = False
        socket_down.close()

    # 文件存在时发送数据包,数据包多次发送用死循环
    while flag:
        # 读取512字节的数据
        read_data = f.read(512)
        ack_code = 3
        # 发送数据包
        send_data = struct.pack("!HH", ack_code, num) + read_data

        # 判断数据大小，数据小于512字节，认为数据读取完毕
        if len(read_data) < 512:
            ack_code = 6
            # 操作码变为6，表示发送的数据包是最后一个并且在控制台打印”传输完成“最后关闭文件
            send_data = struct.pack("!HH", ack_code, num) + read_data
            # 将数据发送以后再退出循环
            socket_down.sendto(send_data, user)
            print('传输完成，对方下载成功')
            if f:
                f.close()
                break

        # 数据正常大小，正常发送操作码为3的数据包
        socket_down.sendto(send_data, user)

        # 发送数据包后接收ACK
        ack_data = socket_down.recv(1024)
        ack_num, num = struct.unpack("!HH", ack_data)
        # 接收到ACK后，将接收到的块编码加一作为下一个数据包的序号
        num += 1

        # 如果操作码异常，退出程序
        if int(ack_num) != 4 or int(ack_num) < 1:
            break
    socket_down.close()

def post(filename, user):
    socket_post = socket(AF_INET, SOCK_DGRAM)

    flag = True
    # 和客户端下载函数类似，但因为服务端第一次接收到的是客户端的上传请求，第二次才能接收到数据，所以需要一个标签
    first = 1
    num = 1
    while flag:
        # 接受客户端的数据
        if first != 1:
            try:
                recv_data = socket_post.recv(1024)
            except:
                print("文件不存在！")
                break
            ack_code = recv_data[1]
            if ack_code == 6:
                print("文件接收完毕！")
                f.close()
                break
            num += 1
            f = open("server_" + filename, 'ab')
            f.write(recv_data[4:])
        # 第一次接受到客户端的请求后改变first的值
        first = 2
        # 向客户端发送ACK
        ack_data = struct.pack("!HH", 4, num)
        socket_post.sendto(ack_data, user)
    socket_post.close()

def main():
    # 接收并且解包客户端的请求
    recv_data, client_port = s.recvfrom(1024)
    if struct.unpack('!b5sb', recv_data[-7:]) == (0, b'octet', 0):
        ack_code = struct.unpack('!H', recv_data[:2])

        # 根据操作码判断客户端想做什么，调用对应的函数
        if ack_code[0] == 2:
            filename = recv_data[2:-7].decode("utf-8")
            print("对方想下载文件："+filename)
            download(filename, client_port)
        elif ack_code[0] == 1:
            filename = recv_data[2:-7].decode("utf-8")
            print("对方想上传文件：" + filename)
            post(filename, client_port)

if __name__ == '__main__':
    main()