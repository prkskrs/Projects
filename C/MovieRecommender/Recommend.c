#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct recommendation_data
{
    char movie_name[30];
    char recommendation_name[30];
    int viewers;
};

typedef struct recommendation_data RD;
RD search_list[200];
RD copy[200];
RD sorted[200],temp;
int global_count = 0;

/**
Function Name: welcome
Input Params: NILL
Return Type: void
Description: Prints a welcome message
**/
void welcome()
{
    int  i = 0;
    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n\t\t\t\tRECOMMENDATION ENGINE\n\n\n");

    for(i=0;i<80;i++)
        printf("*");

    printf("\n\n");

}

/**
Function Name: load_from_file
Input Params: NILL
Return Type: void
Description: loads all the data available with recommendation engine into appropriate data structure
**/
void load_from_file()
{
    FILE *fp;

    /// Open the file in read mode
    fp = fopen("MovieIndex.txt", "r");

    /// Check if the file was successfully opened
    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }

    /// Until the end of the file, read all the file data
    while(!feof(fp))
    {
        fscanf(fp,"%s %s %d", search_list[global_count].movie_name, search_list[global_count].recommendation_name,
                &search_list[global_count].viewers);
        printf("%s %s %d\n",search_list[global_count].movie_name, search_list[global_count].recommendation_name,
                search_list[global_count].viewers);
        global_count++;
    }

    fclose(fp);
}

//search
void search_movie(char movie[], RD search_list)
{
        int i,j,k=0;
	int M = strlen(movie);
	int N = strlen(search_list.movie_name);

  for ( i = 0; i <= N ; i++)
    {
		for (j = 0; j < M; j++)
			if (search_list.movie_name[i + j] != movie[j])
				break;

		if (j == M)
        {
            for (int k = 0; search_list.recommendation_name[k]!='\0'; k++)
            {
                if(search_list.recommendation_name[k]=='-')
                {
                    putchar(' ');

                }
                else{
                    putchar(search_list.recommendation_name[k]);

                }
                
                
            }
            printf("\n");
            

}
}
}



//copying array
void copy_array(RD search_list[], RD copy[])
{       int i=0;
        for (i = 0; i < 200; i++)
        {
                copy[i]=search_list[i];
        }

}


//partition quicksort
int partition(RD copy[],int low ,int high){
    int pivot=copy[low].viewers;
    int i=low;
    int j=high;
    while (i<j)
    {
        while(copy[i].viewers>=pivot){i++;}
        while(copy[j].viewers<pivot){j--;}
        if(i<j)
        {
            temp=copy[i];
            copy[i]=copy[j];
            copy[j]=temp;
            
            
        }

    }
    temp=copy[j];
            copy[j]=copy[low];
            copy[low]=temp;
    
    return j;


}

//sorting based on viewers
void q_sorting(RD copy[],int low, int high){
    if(low<high)
    {
        int pivot=partition(copy,low,high);
        q_sorting(copy,low,pivot-1);
        q_sorting(copy,pivot+1,high);

    }
}

void sorted_display(RD copy[],RD search_list[],int n)
{
    int j=0;
    for (j = 0; j<35; j++)
{
                      
                      printf("%-25s\t",copy[j].movie_name);
                      printf("%-20s\t",copy[j].recommendation_name);
                      printf("%-7d\t\n",copy[j].viewers);
}
}


void convertToUppercase(char *givenStr)
{
    int i;
    for (i = 0; givenStr[i] != '\0'; i++)
    {
        if (givenStr[i] >= 'a' && givenStr[i] <= 'z')
        {
            givenStr[i] = givenStr[i] - 32;
        }
    }
}


void capitalizing(RD copy[])
{
    char *c;
    for (int i = 0; i < 35; i++)
    {
        c=copy[i].recommendation_name;
        convertToUppercase(c);
        
    }
    
}





int main()
{   

    char movie[20];
    printf("Enter moive name for recommendation(**do not give space use '-' instead of space**):");
    scanf("%s",movie);
    welcome();
    load_from_file();
    
    
    // TODO
    
    //copying array
    copy_array(search_list,copy);
    
    //sorting
    q_sorting(copy,0,34);
    
    //capitalizing
    capitalizing(copy);
    
    //sorted array display
    //sorted_display(copy,search_list,35);
    
    //recommending
    printf("\n\n************RECOMMENDED MOVIE AS PER YOUR SEARCH************\n\n");
    for (int i = 0; i < 35; i++)
    {
       search_movie(movie,copy[i]);
    }
            
    

    return 0;
}

