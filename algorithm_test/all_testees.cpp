#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student{
    char name[16];
    int score;
    int rank;
}stu[101];
bool score_cmp(Student a, Student b){
    return a.score > b.score;
}
bool name_cmp(Student a, Student b){
    return strcmp(a.name, b.name) < 0;
}
int main(){
    int stu_n, local_n, total_n, r;
    int stu_s[101];  // 按分数储存的排名数组
    scanf("%d", &local_n);
    
    // 输入每个考场内的考生信息
    total_n = 0;
    for(int i=0; i<local_n; i++){
        scanf("%d", &stu_n);
        for(int j=0; j<stu_n; j++){
            scanf("%s %d", stu[total_n].name, &stu[total_n].score);

            total_n += 1;
        }
        }

    sort(stu, stu + total_n, score_cmp);
    r = 1;
    stu[0].rank = r;
    for(int i=1; i<total_n; i++){
        if(stu[i].score != stu[i-1].score)
        {
            r++;
            stu[i].rank = r;
        }
        else{
            stu[i].rank = r;
        }
    }

    sort(stu, stu + total_n, name_cmp);
    for(int i=0; i<total_n; i++)
    {
        printf("%s %d %d", stu[i].name, stu[i].score, stu[i].rank);
        if(i != total_n-1)printf("\n");
    }
    return 0;
}

