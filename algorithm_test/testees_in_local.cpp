#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std; 
struct Student{
    char name[16];
    int score;
    int rank;
}stu[1001];  // 储存学生信息 
bool score_cmp(Student a, Student b){
    // 按分数排序 
	return a.score > b.score;
}
bool name_cmp(Student a, Student b){
    // 按姓名排序 
	return strcmp(a.name, b.name) < 0;
}
int main(){
    int stu_n, local_n, total_n;
    int stu_s[101];
    
    // 输入考场数量 
    scanf("%d", &local_n);
    
    // 输入每个考场内的考生信息
    total_n = 0;
    for(int i=0; i<local_n; i++){
    	// 输入学生数量 
        scanf("%d", &stu_n);
        for(int j=0; j<stu_n; j++){
        	// 输入每位学生的名字和分数 
            scanf("%s %d", stu[total_n].name, &stu[total_n].score);
			
			//统计学生数量 
            total_n += 1;
        }
        
        // 输入完当前考场学生信息后，对学生进行排序，储存在学生信息的rank中 
        sort(stu + total_n - stu_n, stu + total_n, score_cmp);
        // 第一个学生排名第一 
        stu[total_n-stu_n].rank = 1;
        
		for(int j=total_n-stu_n+1; j<total_n; j++){
            // 分数相同，排名相同，rank不增加 
			if(stu[j].score == stu[j-1].score)
            {
                stu[j].rank = stu[j-1].rank;
            }
            else{
            	//  分数不相同时直接按着人数给rank赋值就好 
                stu[j].rank = j + 1 - (total_n - stu_n);
            }
        }
    }
    
    // 再次排序，输出按姓名排序的结果 
    sort(stu, stu + total_n, name_cmp);
    for(int i=0; i<total_n; i++)
    {
        printf("%s %d %d", stu[i].name, stu[i].score, stu[i].rank);
        if(i != total_n-1)printf("\n");
    }
    return 0;
}

