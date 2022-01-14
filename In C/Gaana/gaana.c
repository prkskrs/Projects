#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include<unistd.h>
// structure to store songs from file to structured array
typedef struct song_list
{
  int song_id;
  char song_name[25];
  char singer_name[20];
  int no_of_likes;
  char album[25];
  char year[4];
  int time;
  }sl;
// structure to create playlist
typedef struct node
{
        char sname[25];
        char artist[20];
        char albname[20];
        struct node *next;
}cp;
cp *head=NULL;
int swch;
// colouring functions
void red(){
  printf("\033[1;31m");
};
void yellow(){
  printf("\033[1;33m");
};
void reset () {
  printf("\033[0m");
};

// create playlist
void create_playlist ()
{
        cp *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));

        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                exit(0);
        }

        printf("Enter Track Name:");
        scanf("%s",temp->sname);

        printf("Enter Artist Name:");
        scanf("%s",temp->artist);

        printf("Enter Album Name:");
        scanf("%s",temp->albname);

        temp->next=NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                ptr=head;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}


// display playlist
void display_playlist()
{
        cp *ptr;
        if(head==NULL)
        {
                printf("\n\n****  No Songs In Playlist To Display  ****\n\n");
                return;
        }
        else
        {
                ptr=head;
                printf("%-25s%-20s%-25s\n","|Song Name|","|Artist Name|","|Album Name|");
                while(ptr!=NULL)
                {
                        printf("%-25s",ptr->sname);

                        printf("%-20s",ptr->artist);

                        printf("%-25s",ptr->albname);

                        ptr=ptr->next ;
                        printf("\n");
                }
        }
}


// add song in playlist
void add_song(){


        cp *temp,*ptr;

        temp=(struct node *)malloc(sizeof(struct node));

        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                return;
        }

        printf("Enter Track Name:");
        scanf("%s",temp->sname);

        printf("Enter Artist Name:");
        scanf("%s",temp->artist);

        printf("Enter Album Name:");
        scanf("%s",temp->albname);

        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                ptr=head;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }

}


// remove song using position
void remove_song()
{
        int i,pos;
        char rsong;
        cp *temp,*ptr;
        if(head==NULL)
        {
                printf("\n\n****************************************** No Songs In Playlist ******************************************\n\n\n\n");

        }
        else
        {
                printf("Song Position To Remove : ");
                scanf("%d",&pos);
                if(pos==1)
                {
                        ptr=head;
                        head=head->next ;

                        printf("\n\n Removing '%s' from playlist.....\n",ptr->sname);

                        printf("\n\n Removed!!\n\n");
                        free(ptr);
                }
                else
                {
                        ptr=head;
                        for(i=0;i<pos-1;i++)
                        {
                          temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {

                                        printf("No Songs At this position in playlist\n");
                                        return;

                                }
                        }
                        temp->next =ptr->next ;

                        printf("\n\n Removing '%s' from playlist.....\n",ptr->sname);

                        printf("\n\n Removed!!\n\n");

                        free(ptr);
                }

}
}



//welcome function
void menu(){
  red();

    printf("\t\t\t#    #\t#####\t#    \t#####\t#####\t##   ##\t#####\n");
    printf("\t\t\t#    #\t#    \t#    \t#    \t#   #\t# # # #\t#    \n");
    printf("\t\t\t#    #\t#### \t#    \t#    \t#   #\t#  #  #\t#### \n");
    printf("\t\t\t# ## #\t#    \t#    \t#    \t#   #\t#     #\t#    \n");
    printf("\t\t\t##  ##\t#####\t#####\t#####\t#####\t#     #\t#####\n");
    printf("\n");

    reset();

    printf("\t\t\t\t\t\t#####\t#####\n");
    printf("\t\t\t\t\t\t  #  \t#   #\n");
    printf("\t\t\t\t\t\t  #  \t#   #\n");
    printf("\t\t\t\t\t\t  #  \t#   #\n");
    printf("\t\t\t\t\t\t  #  \t#####\n");
    printf("\n");

    red();

    printf("\t\t\t\t#####\t#####\t#####\t#    #\t  #####\n");
    printf("\t\t\t\t#    \t#   #\t#   #\t# #  #\t  #   #\n");
    printf("\t\t\t\t# ###\t#####\t#####\t#  # #\t  #####\n");
    printf("\t\t\t\t#   #\t#   #\t#   #\t#    #\t  #   #\n");
    printf("\t\t\t\t#####\t#   #\t#   #\t#    #\t  #   #\n");

reset();
}



// search song
void search_song(char search[], sl songlist)
{
	int M = strlen(search);

	int N = strlen(songlist.song_name);



	for (int i = 0; i <= N ; i++)
    {
		int j;
		for (j = 0; j < M; j++)
			if (songlist.song_name[i + j] != search[j])
				break;

		if (j == M)
        {
            printf("%-25s\t",songlist.song_name);
            printf("%-20s\t",songlist.singer_name);
            printf("%-7d\t",songlist.no_of_likes);
            printf("%-25s\t\n",songlist.album);

        }

}
}

// select song
void select_song(char search[], sl songlist)
{
	int M = strlen(search);
	int N = strlen(songlist.song_name);

	for (int i = 0; i <= N ; i++)
        {
                int j;
                for (j = 0; j < M; j++)
			if (songlist.song_name[i + j] != search[j])
				break;
                                if (j == M)
                                {      printf("\n\n'SELECTED' %s by %s\n\n",songlist.song_name,songlist.singer_name);

                                       while (1)


                                       {
                                               printf("1:Play '%s'\n",songlist.song_name);
                                               printf("2:Play 'Next Song'");
                                               printf("\n\nEnter Choice:");
                                               scanf("%d",&swch);
                                               switch (swch)
                                               {
                                               case 1:  printf("\n\n Now Playing......\n\n");

                                                        for (int i=0;i<songlist.time;i++)
                                                        {
                                                                printf(">");
                                                                sleep(1);
                                                                fflush(stdout);
                                                        }
                                                        printf("\n\n");
                                                        break;
                                                case 2:
                                                       return;


                                               default:printf("invalid choice!!");
                                                       break;
                                               }

                                       }






                                }
        }

}




// search singer name
void search_singer(char singer[], sl songlist)
{
        int i,j;
	int M = strlen(singer);
	int N = strlen(songlist.singer_name);

  for ( i = 0; i <= N ; i++)
    {
		for (j = 0; j < M; j++)
			if (songlist.singer_name[i + j] != singer[j])
				break;

		if (j == M)
        {
            printf("%-25s\t",songlist.song_name);
            printf("%-20s\t",songlist.album);
            printf("%-4d\t\n",songlist.no_of_likes);

}
}
}




void copy_array(sl songlist[], sl copy[])
{       int i=0;
        for (i = 0; i < 200; i++)
        {
                copy[i]=songlist[i];
        }

}


// swapping in quicksort
void swap(sl copy[],int i,int j){
    int likes=copy[i].no_of_likes;
    copy[i].no_of_likes=copy[j].no_of_likes;
    copy[j].no_of_likes=likes;

    int id=copy[i].song_id;
    copy[i].song_id=copy[j].song_id;
    copy[j].song_id=id;


    int tme=copy[i].time;
    copy[i].time=copy[j].time;
    copy[j].time=tme;




}



//partition quicksort
int partition(sl copy[],int low ,int high){
    int pivot=copy[low].no_of_likes;
    int i=low;
    int j=high;
    while (i<j)
    {
        while(copy[i].no_of_likes<=pivot){i++;}
        while(copy[j].no_of_likes>pivot){j--;}
        if(i<j)
        {
            swap(copy,i,j);
        }

    }
    swap(copy,j,low);
    return j;


}


//sorting based on like
void mostlikedsong(sl copy[],int low, int high){
    if(low<high)
    {
        int pivot=partition(copy,low,high);
        mostlikedsong(copy,low,pivot-1);
        mostlikedsong(copy,pivot+1,high);

    }
}


// display sorting based on like
void display_sort(sl copy[], sl songlist[],int n)
{
int i=0,j=0;
    for (i = n-1; i>=0; i--)
{
        for (j=n-1; j>=0; j--)
        {
                if(songlist[j].no_of_likes==copy[i].no_of_likes)
                {
                      printf("%-25s\t",songlist[j].song_name);
                      printf("%-20s\t",songlist[j].singer_name);
                      printf("%-25s\t",songlist[j].album);
                      printf("%-7d\t\n",songlist[j].no_of_likes);


                }
        }

    }

}




// search by year
void search_by_year(char year[], sl songlist)
{
        int i,j;
	int M = strlen(year);
	int N = strlen(songlist.year);

  for (i = 0; i <= N ; i++)
    {

		for (j = 0; j < M; j++)
			{
                                if (songlist.year[i + j] != year[j])
				break;
                        }

        if ( j==M)
        {
            printf("%-25s\t",songlist.song_name);
            printf("%-20s\t",songlist.album);
            printf("%-4d\t\n",songlist.no_of_likes);
       }
}
}



//main function
int main()
{
  char patt[20];
  char sing[20];
  sl songlist[200];
  sl copy[200];
  char yr[4];
  int i=0,j=0;
  char selected_song[20];

  menu();

    FILE *song1;
    song1 = fopen("song.txt","rb");

    if (song1== NULL)
    {
    printf("can not open file \n");
    return 1;
    }



    /*fetching input from file*/
    for (i = 0; i < 200; i++)
    {
      fscanf(song1,"%d",&songlist[i].song_id);
      fscanf(song1,"%s",songlist[i].song_name);
      fscanf(song1,"%s",songlist[i].singer_name);
      fscanf(song1,"%d",&songlist[i].no_of_likes);
      fscanf(song1,"%s",songlist[i].album);
      fscanf(song1,"%s",songlist[i].year);
      fscanf(song1,"%d",&songlist[i].time);


    }

  int ch;

  do

  {

    printf("\n\n1)--> Search Songs\n");
    printf("2)--> Search Singer's Profile\n");
    printf("3)--> Select/Play Songs\n");
    printf("4)--> Create Playlist\n");
    printf("5)--> Add Song In Playlist\n");
    printf("6)--> Open Playlist\n");
    printf("7)--> Remove Songs From Playlist\n");
    printf("8)--> Most Liked Song\n");
    printf("9)--> Search Songs By Year Of Release\n");
    printf("10)--> Exit the program\n\n");
    printf("Select Functions To Perform -->");
    scanf("%d",&ch);



    switch (ch)
    {

   case 1:
            printf("Song Name:");
            scanf("%s",patt);

            printf("----------------------------Recommended songs as per your search----------------------------\n\n");
            printf("%-25s\t%-20s\t%-7s\t%4s\n\n","|Song Name|","|Singer Name|","|Likes|","|Album|");



            for (i = 0; i < 200; i++)
            {
              search_song(patt,songlist[i]);
            }
            printf("\n");

            // if(t==0)
            // {
            //     printf("'%s' no such song available\n",patt);
            // }

        break;



    case 2: printf("Singer Name:");
            scanf("%s",sing);

            printf("----------------------------[%s's] Songs----------------------------\n\n",sing);
            printf("%-25s\t%-20s\t%-4s\t\n\n","|Song Name|","|Album|","|Likes|");

            for (i = 0; i < 200; i++)
            {
              search_singer(sing,songlist[i]);
            }
            printf("\n");
            break;



    case 3: printf("\nSelect Song To Play:");
            scanf("%s",selected_song);

            for (i = 0; i < 200; i++)
            {
                select_song(selected_song,songlist[i]);
            }
            printf("Sorry :(  No More Songs Related To Your Choice '%s'\n\n",selected_song);
            break;



    case 4: create_playlist();
            break;


    case 5: add_song();
            break;


    case 6: display_playlist();
            break;


    case 7: remove_song();
            break;


    case 8: copy_array(songlist,copy);
            mostlikedsong(copy,0,199);
            display_sort(copy,songlist,200);
            break;
    case 9: printf("Enter Year(YYYY) To Get Songs: ");
            scanf("%s",yr);
            printf("----------------------------[%s's] Songs----------------------------\n\n",yr);
            printf("%-25s\t%-20s\t%-4s\t\n\n","|Song Name|","|Album|","|Likes|");
            for (i = 0; i < 200; i++)
            {
                search_by_year(yr,songlist[i]);
            }

            break;
    case 10: exit(0);
             break;

    default: printf("INVALID CHOICE\n\n");
      break;
    }

  } while (ch!=10);

  return 0;

}








