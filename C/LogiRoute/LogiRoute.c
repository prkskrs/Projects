#include<stdio.h>
#include<stdlib.h>



//dijkstra on price
void dijprice(int price[21][21],int startcity,int endcity)
{
    int cost[21][21],dist[21],pred[21];
    int visited[21],count,mindist,nextcity,i,j;

    for(i=1;i<=20;i++)
    {
        for(j=1;j<=20;j++)
        {
            if(price[i][j]==0)
            {
                cost[i][j]=99999;
            }
            else
            {
                cost[i][j]=price[i][j];
            }
        }
    }


    for(i=1;i<=20;i++)
    {
        dist[i]=cost[startcity][i];
        pred[i]=startcity;
        visited[i]=0;
    }


    dist[startcity]=0;
    visited[startcity]=1;
    count=1;


    while(count<20-1)
    {
        mindist=99999;

        for(i=1;i<=20;i++)
        {
            if(dist[i]<mindist && !visited[i])
            {
                mindist=dist[i];
                nextcity=i;
            }
        }

        visited[nextcity]=1;

        for(i=1;i<=20;i++)
        {
            if(!visited[i])
            {
                if(mindist+cost[nextcity][i]<dist[i])
                {
                    dist[i]=mindist+cost[nextcity][i];
                    pred[i]=nextcity;
                }
            }
        }

        count++;
    }


    for(i=1;i<=20;i++)
    {
        if(i!=startcity && i==endcity)
        {
            printf("Cheapest Flight Route to ");
            if(i==1)
            {
                printf("Delhi ");
            }

            if(i==2)
            {
                printf("Mumbai ");
            }

            if(i==3)
            {
                printf("Bangalore ");
            }

            if(i==4)
            {
                printf("Hyderabad ");
            }

            if(i==5)
            {
                printf("Kolkata ");
            }

            if(i==6)
            {
                printf("Chennai ");
            }

            if(i==7)
            {
                printf("Ahmedabad ");
            }

            if(i==8)
            {
                printf("Jaipur ");
            }

            if(i==9)
            {
                printf("Goa ");
            }

            if(i==10)
            {
                printf("Hubli ");
            }

            if(i==11)
            {
                printf("Kanpur ");
            }

            if(i==12)
            {
                printf("Patna ");
            }

            if(i==13)
            {
                printf("Chandigarh ");
            }

            if(i==14)
            {
                printf("Lucknow ");
            }

            if(i==15)
            {
                printf("Kochi ");
            }

            if(i==16)
            {
                printf("Pune ");
            }

            if(i==17)
            {
                printf("Jammu ");
            }

            if(i==18)
            {
                printf("Bhopal ");
            }

            if(i==19)
            {
                printf("Dehradun ");
            }

            if(i==20)
            {
                printf("Guwahati ");
            }

            printf("is of Rs %d\n",dist[i]);

            printf("Route = ");
            if(i==1)
            {
                printf("DEL");
            }

            if(i==2)
            {
                printf("BOM");
            }

            if(i==3)
            {
                printf("BLR");
            }

            if(i==4)
            {
                printf("HYD");
            }

            if(i==5)
            {
                printf("CCU");
            }

            if(i==6)
            {
                printf("MAA");
            }

            if(i==7)
            {
                printf("AMD");
            }

            if(i==8)
            {
                printf("JAI");
            }

            if(i==9)
            {
                printf("GOI");
            }

            if(i==10)
            {
                printf("HBX");
            }

            if(i==11)
            {
                printf("KNU");
            }

            if(i==12)
            {
                printf("PAT");
            }

            if(i==13)
            {
                printf("IXC");
            }

            if(i==14)
            {
                printf("LKO");
            }

            if(i==15)
            {
                printf("COK");
            }

            if(i==16)
            {
                printf("PNQ");
            }

            if(i==17)
            {
                printf("IXJ");
            }

            if(i==18)
            {
                printf("BHO");
            }

            if(i==19)
            {
                printf("DED");
            }

            if(i==20)
            {
                printf("GAU");
            }

            j=i;

            do
            {
                j=pred[j];
                if(j==1)
                {
                    printf(" <-- DEL");
                }

                else if(j==2)
                {
                    printf(" <-- BOM");
                }

                else if(j==3)
                {
                    printf(" <-- BLR");
                }

                else if(j==4)
                {
                    printf(" <-- HYD");
                }

                else if(j==5)
                {
                    printf(" <-- CCU");
                }

                else if(j==6)
                {
                    printf(" <-- MAA");
                }

                else if(j==7)
                {
                    printf(" <-- AMD");
                }

                else if(j==8)
                {
                    printf(" <-- JAI");
                }

                else if(j==9)
                {
                    printf(" <-- GOI");
                }

                else if(j==10)
                {
                    printf(" <-- HBX");
                }

                else if(j==11)
                {
                    printf(" <-- KNU");
                }

                else if(j==12)
                {
                    printf(" <-- PAT");
                }

                else if(j==13)
                {
                    printf(" <-- IXC");
                }

                else if(j==14)
                {
                    printf(" <-- LKO");
                }

                else if(j==15)
                {
                    printf(" <-- COK");
                }

                else if(j==16)
                {
                    printf(" <-- PNQ");
                }

                else if(j==17)
                {
                    printf(" <-- IXJ");
                }

                else if(j==18)
                {
                    printf(" <-- BHO");
                }

                else if(j==19)
                {
                    printf(" <-- DED");
                }

                else if(j==20)
                {
                    printf(" <-- GAU");
                }

                else
                {
                    printf(" <- %d",j);
                }
            }
            while(j!=startcity);
        }
    }
    printf("\n\n");

}


//dijkstra on time
void dijtime(float time[21][21],int startcity,int endcity)
{
    float clock[21][21],timex[21],predtime[21],mintime;
    int visitedtime[21],countt,nextcity,i,j;

    for(i=1;i<=20;i++)
    {
        for(j=1;j<=20;j++)
        {
            if(time[i][j]==0)
            {
                clock[i][j]=99999;
            }
            else
            {
                clock[i][j]=time[i][j];
            }
        }
    }


    for(i=1;i<=20;i++)
    {
        timex[i]=clock[startcity][i];
        predtime[i]=startcity;
        visitedtime[i]=0;
    }


    timex[startcity]=0;
    visitedtime[startcity]=1;
    countt=1;


    while(countt<20-1)
    {
        mintime=99999;

        for(i=1;i<=20;i++)
        {
            if(timex[i]<mintime && !visitedtime[i])
            {
                mintime=timex[i];
                nextcity=i;
            }
        }

        visitedtime[nextcity]=1;

        for(i=1;i<=20;i++)
        {
            if(!visitedtime[i])
            {
                if(mintime+clock[nextcity][i]<timex[i])
                {
                    timex[i]=mintime+clock[nextcity][i];
                    predtime[i]=nextcity;
                }
            }
        }

        countt++;
    }


    for(i=1;i<=20;i++)
    {
        if(i!=startcity && i==endcity)
        {
            printf("Fastest Flight Route to ");

            if(i==1)
            {
                printf("Delhi ");
            }

            if(i==2)
            {
                printf("Mumbai ");
            }

            if(i==3)
            {
                printf("Bangalore ");
            }

            if(i==4)
            {
                printf("Hyderabad ");
            }

            if(i==5)
            {
                printf("Kolkata ");
            }

            if(i==6)
            {
                printf("Chennai ");
            }

            if(i==7)
            {
                printf("Ahmedabad ");
            }

            if(i==8)
            {
                printf("Jaipur ");
            }

            if(i==9)
            {
                printf("Goa ");
            }

            if(i==10)
            {
                printf("Hubli ");
            }

            if(i==11)
            {
                printf("Kanpur ");
            }

            if(i==12)
            {
                printf("Patna ");
            }

            if(i==13)
            {
                printf("Chandigarh ");
            }

            if(i==14)
            {
                printf("Lucknow ");
            }

            if(i==15)
            {
                printf("Kochi ");
            }

            if(i==16)
            {
                printf("Pune ");
            }

            if(i==17)
            {
                printf("Jammu ");
            }

            if(i==18)
            {
                printf("Bhopal ");
            }

            if(i==19)
            {
                printf("Dehradun ");
            }

            if(i==20)
            {
                printf("Guwahati ");
            }


            printf("will take %.2f Hours\n",timex[i]);
            printf("Route = ");
            if(i==1)
            {
                printf("DEL");
            }

            if(i==2)
            {
                printf("BOM");
            }

            if(i==3)
            {
                printf("BLR");
            }

            if(i==4)
            {
                printf("HYD");
            }

            if(i==5)
            {
                printf("CCU");
            }

            if(i==6)
            {
                printf("MAA");
            }

            if(i==7)
            {
                printf("AMD");
            }

            if(i==8)
            {
                printf("JAI");
            }

            if(i==9)
            {
                printf("GOI");
            }

            if(i==10)
            {
                printf("HBX");
            }

            if(i==11)
            {
                printf("KNU");
            }

            if(i==12)
            {
                printf("PAT");
            }

            if(i==13)
            {
                printf("IXC");
            }

            if(i==14)
            {
                printf("LKO");
            }

            if(i==15)
            {
                printf("COK");
            }

            if(i==16)
            {
                printf("PNQ");
            }

            if(i==17)
            {
                printf("IXJ");
            }

            if(i==18)
            {
                printf("BHO");
            }

            if(i==19)
            {
                printf("DED");
            }

            if(i==20)
            {
                printf("GAU");
            }


            j=i;

            do
            {
                j=predtime[j];
                if(j==1)
                {
                    printf(" <-- DEL");
                }

                else if(j==2)
                {
                    printf(" <-- BOM");
                }

                else if(j==3)
                {
                    printf(" <-- BLR");
                }

                else if(j==4)
                {
                    printf(" <-- HYD");
                }

                else if(j==5)
                {
                    printf(" <-- CCU");
                }

                else if(j==6)
                {
                    printf(" <-- MAA");
                }

                else if(j==7)
                {
                    printf(" <-- AMD");
                }

                else if(j==8)
                {
                    printf(" <-- JAI");
                }

                else if(j==9)
                {
                    printf(" <-- GOI");
                }

                else if(j==10)
                {
                    printf(" <-- HBX");
                }

                else if(j==11)
                {
                    printf(" <-- KNU");
                }

                else if(j==12)
                {
                    printf(" <-- PAT");
                }

                else if(j==13)
                {
                    printf(" <-- IXC");
                }

                else if(j==14)
                {
                    printf(" <-- LKO");
                }

                else if(j==15)
                {
                    printf(" <-- COK");
                }

                else if(j==16)
                {
                    printf(" <-- PNQ");
                }

                else if(j==17)
                {
                    printf(" <-- IXJ");
                }

                else if(j==18)
                {
                    printf(" <-- BHO");
                }

                else if(j==19)
                {
                    printf(" <-- DED");
                }

                else if(j==20)
                {
                    printf(" <-- GAU");
                }

                else
                {
                    printf(" <- %d",j);
                }
            }
            while(j!=startcity);
        }
    }
    printf("\n\n");

}


int main()
{

    int price[21][21];
    float time[21][21];
    int u,v;
    FILE *price1,*time1;
    price1 = fopen("price.txt","rb");
    
    time1 = fopen("time.txt","rb");
    if (price1== NULL)
    {
    printf("can not open file \n");
    return 1;
    }

    
    
    
    
    
    /*fetching input from file*/

    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j < 21; j++)
        {
            fscanf(price1,"%d",&price[i][j]);
        }
        
    }
    
    
    
    
    /*price matrix print*/
    
    /*for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j < 21; j++)
        {
            printf("%d\t", price[i][j]);
        }
        printf("\n");
    }*/
    
    
    
    
    if (time1== NULL)
    {
    printf("can not open file \n");
    return 1;
    }
    
    
    
    
    /*fetching time input from file*/

    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j < 21; j++)
        {
            fscanf(time1,"%f",&time[i][j]);
        }
        
    }
    
    /*time matrix print*/
   /* for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j < 21; j++)
        {
            printf("%.2f\t", time[i][j]);
        }
        printf("\n");
           
    }*/
    


    printf("-------------------------------------------------------LOG!ROUTE-------------------------------------------------------\n\n");
    printf("-----------------------------------------------Plan Your Journey With Us-----------------------------------------------\n\n");
    printf("Please Refer to Code Table\n\n");
    printf("  1 - Delhi(DEL)           2 - Mumbai(BOM)\n");
    printf("  3 - Bangalore(BLR)       4 - Hyderabad(HYD)\n");
    printf("  5 - Kolkata(CCU)         6 - Chenani(MAA)\n");
    printf("  7 - Ahmedabad(AMD)       8 - Jaipur(JAI)\n");
    printf("  9 - Goa(GOI)            10 - Hubli(HBX)\n");
    printf(" 11 - Kanpur(KNU)         12 - Patna(PAT)\n");
    printf(" 13 - Chandigarh(IXC)     14 - Lucknow(LKO)\n");
    printf(" 15 - Kochi(COK)          16 - Pune(PNQ)\n");
    printf(" 17 - Jammu(IXJ)          18 - Bhopal(BHO)\n");
    printf(" 19 - Dehradun(DED)       20 - Guwahati(GAU)\n");

    printf("\n\n");

    printf("From : ");
    scanf("%d",&u);
    if(u>20 || u<1)
    {
        printf("Invalid Input\n");
        exit(0);
    }
    printf("To : ");
    scanf("%d",&v);
    if(u>20 || u<1)
    {
        printf("Invalid Input\n");
        exit(0);
    }


    printf("\n\n");

    dijprice(price,u,v);

    dijtime(time,u,v);

}





