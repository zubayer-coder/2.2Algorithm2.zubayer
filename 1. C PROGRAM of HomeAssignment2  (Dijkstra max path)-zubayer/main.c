/**********************************
*   Sk.Md. Zubayer-Al-Mahmud
*   ID: 1017311014
*   PDG in ICT, BUET.
**********************************/

#include<stdio.h>
#define MAX 6

void dijkstra(int G[MAX][MAX],int n,int startnode);

int main()
{
    printf("\tSk. Md. Zubayer-Al-Mahmud\n\tID: 1017311014\n\tPDG in ICT, BUET.\n");
    printf("*******************************************\n\n");
    printf("In the given Graph have 6 vertices \nThese are: A, B, C, D, E, F \nAnd Source Vertex: A\n");
	int G[MAX][MAX]={{0,6,5,0,0,0},{0,0,5,0,3,2},{0,5,0,2,0,3},{0,0,0,0,0,1},{0,0,0,4,0,0},{0,0,0,0,3,0}};
	int n=6,u=0;

//	int i,j;
//	printf("\nEnter the adjacency matrix:\n");
//
//	for(i=0;i<n;i++)
//		for(j=0;j<n;j++)
//			scanf("%d",&G[i][j]);
//
//	printf("\nEnter the starting node:");
//	scanf("%d",&u);

	dijkstra(G,n,u);

	return 0;
}

void dijkstra(int G[MAX][MAX],int n,int startnode)
{   char s[6]={'A','B','C','D','E','F'};
	int distance[MAX],pred[MAX];
	int visited[MAX],count,maxdistance,nextnode,i,j;

	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//initialize pred[],distance[] and visited[]
	for(i=0;i<n;i++)
	{
		distance[i]=G[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<n-1)
	{
		maxdistance=0;//  max =0;

		//nextnode gives the node at maximum distance
		for(i=0;i<n;i++)
			if(distance[i]>maxdistance&&!visited[i])//............>
			{
				maxdistance=distance[i];
				nextnode=i;
			}

			//check if a better path exists through nextnode
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(maxdistance+G[nextnode][i]>distance[i])//.......
					{
						distance[i]=maxdistance+G[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

	//print the path and distance of each node
	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance from node %c to node %c = %d",s[0],s[i],distance[i]);
		//	printf("\nPath= %c",s[i]); //A
            printf("\nPath= ");
			j=i;
			int k=0;
			char p[6]={};
			do
			{
				j=pred[j];
				p[k]=s[j];
				k++;
//				printf(" <-- %c",s[j]);
			}while(j!=startnode);

// print by while loop
//            k--;
//			while(k!=-1)
//            {
//               printf("%c --> ",p[k]);
//               k--;
//            }
//...................
// print by for loop
            int m;
			for (m=k-1;m>=0;m--)
            {
                printf("%c --> ",p[m]);
            }
//...................

            printf("%c",s[i]);
			printf("\n");
	}
}
