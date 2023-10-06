from socket import *
import struct

host_port = ("127.0.0.1", 69)
client = socket(AF_INET, SOCK_DGRAM)

def download(filename):
    while True:
        # 发送请求
        request_data = struct.pack("!H%dsb5sb" % len(filename), 2, filename.encode('utf-8'), 0, 'octet'.encode('utf-8'), 0)
        client.sendto(request_data, host_port)

        # 接收服务器发送的数据
        recv_data, (sever_ip, sever_port) = client.recvfrom(1024)
        ack_code, num = struct.unpack("!HH", recv_data[:4])

        # 判断操作码
        # 操作码为5，服务器返回错误，循环中断
        if ack_code == 5:
            print(f"服务器返回{filename}不存在！")
            break

        # 操作码为3，服务器发送数据，客户端接收数据后发送ACK
        elif ack_code == 3:
            ack_data = struct.pack("!HH", 4, num)
            client.sendto(ack_data, (sever_ip, sever_port))
            f = open("client_" + filename, 'ab')
            f.write(recv_data[4:])

        # 操作码为6，服务器数据发送完毕，客户端关闭文件并且关闭套接字
        elif ack_code == 6:
            print("客户端下载完毕！")
            f.close()
            break

        # 异常操作码跳出循环
        else:
            print("异常！")
            break
    client.close()

def post(filename):
    client_post = socket(AF_INET, SOCK_DGRAM)
    request_data = struct.pack("!H%dsb5sb" % len(filename), 1, filename.encode('utf-8'), 0, 'octet'.encode('utf-8'),0)
    client_post.sendto(request_data, host_port)
    num = 1
    flag = True
    try:
        f = open(filename, 'rb')
    except:
        print("文件不存在！")
        flag = False

    while flag:
        # 和服务端发送数据类似
        ack_data, (sever_ip, sever_port) = client_post.recvfrom(1024)
        # 判断操作码
        ack_num, num = struct.unpack("!HH", ack_data)
        # 操作码为4表示服务端收到数据，继续向服务端发送数据
        if ack_num == 4:
            read_data = f.read(512)
            ack_code = 3
            send_data = struct.pack("!HH", ack_code, num) + read_data
            if len(read_data) < 512:
                ack_code = 6
                send_data = struct.pack("!HH", ack_code, num) + read_data
                client_post.sendto(send_data, (sever_ip, sever_port))
                f.close()
                print('传输完成，对方下载成功')
                break
            client_post.sendto(send_data, (sever_ip, sever_port))
        # 操作码异常退出循环
        else:
            break
    client_post.close()





def main():
    # 设计简单的界面，让用户选择上传或下载
    print("按1选择上传文件\n按2选择下载文件")
    answer = input("请选择：")

    if answer == '2':
        filename = input("请输入文件名字：")
        download(filename)

    if answer == '1':
        filename = input("请输入文件名字：")
        post(filename)

if __name__ == '__main__':
    main()
