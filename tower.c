// tower.c
#include<stdio.h>
#include<stdlib.h>


void printscrn(int n,int arr[],int ind[]){
		for(int i=n-1;i>=0;i--){
			if(ind[0]>=i && arr[ind[0]]!=0 ){printf("%d",arr[i]);}
				else if(i==0 ){printf("-");}
				else{printf(" ");}
			if(ind[1]>=i && arr[n+ind[1]]!=0){printf("\t%d",arr[n+i]);}
				else if(i==0){printf("\t-");}
				else{printf("\t ");}
			if(ind[2]>=i && arr[2*n + ind[2]]!=0){printf("\t%d",arr[2*n+i]);}
				else if(i==0){printf("\t-");}
				else{printf("\t ");}
			printf("\n");
		}
}

int optimal_scr(int n){
	int count=1,i=0;
	if(n==1){return 1;}
	while(i<n-1){
		count=count*2+1;
		i++;
	}
	return count;
}

void play(){
	int n;
	printf("Enter n:\n");
	scanf("%d",&n);
	int *arr =(int*)calloc(n*3,sizeof(int));
	int j=1;
	for(int i=n-1;i>=0;i--){arr[i]=j;j++;}
	
	int a,b,count=0,count1=0;
	int ind[3]={n-1,0,0};
	int flg=0,flg1=0;
	count1=optimal_scr(n);
	while(arr[2*n-1]!=1&&arr[3*n-1]!=1){

		printscrn(n,arr,ind);

		printf("Enter from and to .enter 4 4 to exit\n");
		scanf("%d %d",&a,&b);
		if(a==4&&b==4){flg1=1;break;}
		if( (arr[n*(a-1)+ind[a-1]] > arr[n*(b-1)+ind[b-1]] && arr[n*(b-1)+ind[b-1]]!=0 ) || arr[n*(a-1)+ind[a-1]]==0 ){
			printf("Invalid move.Try again.\n");
			continue;
		}
		count++;
		if(arr[n*(b-1)+ind[b-1]]==0){
			arr[n*(b-1)+ind[b-1]] = arr[n*(a-1)+ind[a-1]] ;

		}else{
			ind[b-1]++;
			arr[n*(b-1)+ind[b-1]] = arr[n*(a-1)+ind[a-1]] ;
		}
		arr[n*(a-1)+ind[a-1]]=0;
		
		// if(flg==1){
		// 	flg=0;
		// }else{ind[b-1]++;}
		
		if(ind[a-1]!=0)	
		ind[a-1]--;
		//else ind[a-1]=0;
		//printf("ind[0] : %d - %d\nind[1] : %d - %d\nind[2] : %d - %d\ncount : %d\n",ind[0],arr[ind[0]],ind[1],arr[n+ind[1]],ind[2],arr[2*n+ind[2]],count );
		//for(int i=0;i<3*n;i++){printf("%d",arr[i]);}printf("\n");
	}
	if(flg1==0){
		printscrn(n,arr,ind);
	printf("Congratulations!\nYou did it.Your score: %d.Optimal score: %d\nPress 1 to play again.Press 0 to end\n",count,count1);
	}
	else{
		printf("Press 1 to play.Press 0 to end\n");
	}
	scanf("%d",&flg);
	if(flg==1){free(arr); play();}
	
}	


int main(){
		printf("Hello,Trveller!Welcome to the Tower of Hanoi.Enjoy!:)\n");
		play();
	
	
	return 0;
}
