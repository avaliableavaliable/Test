#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std; 
struct Student{
    char name[16];
    int score;
    int rank;
}stu[1001];  // ����ѧ����Ϣ 
bool score_cmp(Student a, Student b){
    // ���������� 
	return a.score > b.score;
}
bool name_cmp(Student a, Student b){
    // ���������� 
	return strcmp(a.name, b.name) < 0;
}
int main(){
    int stu_n, local_n, total_n;
    int stu_s[101];
    
    // ���뿼������ 
    scanf("%d", &local_n);
    
    // ����ÿ�������ڵĿ�����Ϣ
    total_n = 0;
    for(int i=0; i<local_n; i++){
    	// ����ѧ������ 
        scanf("%d", &stu_n);
        for(int j=0; j<stu_n; j++){
        	// ����ÿλѧ�������ֺͷ��� 
            scanf("%s %d", stu[total_n].name, &stu[total_n].score);
			
			//ͳ��ѧ������ 
            total_n += 1;
        }
        
        // �����굱ǰ����ѧ����Ϣ�󣬶�ѧ���������򣬴�����ѧ����Ϣ��rank�� 
        sort(stu + total_n - stu_n, stu + total_n, score_cmp);
        // ��һ��ѧ��������һ 
        stu[total_n-stu_n].rank = 1;
        
		for(int j=total_n-stu_n+1; j<total_n; j++){
            // ������ͬ��������ͬ��rank������ 
			if(stu[j].score == stu[j-1].score)
            {
                stu[j].rank = stu[j-1].rank;
            }
            else{
            	//  ��������ͬʱֱ�Ӱ���������rank��ֵ�ͺ� 
                stu[j].rank = j + 1 - (total_n - stu_n);
            }
        }
    }
    
    // �ٴ������������������Ľ�� 
    sort(stu, stu + total_n, name_cmp);
    for(int i=0; i<total_n; i++)
    {
        printf("%s %d %d", stu[i].name, stu[i].score, stu[i].rank);
        if(i != total_n-1)printf("\n");
    }
    return 0;
}

