#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

  int CHE_score = 0;
  int MUN_score = 0;
  int LIV_score = 0;
  int NEW_score = 0;

  for(int i = 0; i < 6; i++)
  {

    int a; scanf("%d", &a);
    int b; scanf("%d", &b);
    
    if(i == 0)
    {
      if(a == b){
        CHE_score++;
        LIV_score++;
      }
      else if(a > b){
        CHE_score += 3;
      }
      else{
        LIV_score += 3;
      }
    }
    else if(i == 1)
    {
      if(a == b){
        CHE_score++;
        MUN_score++;
      }
      else if(a > b){
        CHE_score += 3;
      }
      else{
        MUN_score += 3;
    
      }
    }
    else if(i == 2)
    {
      if(a == b)
      {
        CHE_score++;
        NEW_score++;
      }
      else if(a > b)
      {
        CHE_score += 3;
      }
      else
      {
        NEW_score += 3;
      }
    }
    else if(i == 3)
    {
      if(a == b)
      {
        LIV_score++;
        MUN_score++;
      }
      else if(a > b)
      {
        LIV_score += 3;
      }
      else
      {
        MUN_score += 3;
      }
    }
    
    else if(i == 4)
    {
      if(a == b)
      {
        LIV_score++;
        NEW_score++;
      }
      else if(a > b)
      {
        LIV_score += 3;
      }
      else
      {
        NEW_score += 3;
      }
    }
    else if(i == 5)
    {
      if(a == b)
      {
        MUN_score++;
        NEW_score++;
      }
      else if(a > b)
      {
        MUN_score += 3;
      }
      else{
        NEW_score += 3;
      }
    }
  }

  char teams[][10] = {"MUN", "LIV", "NEW", "CHE"};
  int scores[] = {MUN_score, LIV_score, NEW_score, CHE_score};
  int n = 4;

  // Bubble Sort
  for(int i = 0; i < n - 1; i++)
  {
    for(int j = 0; j < n - i - 1; j++)
    {
      if(scores[j] < scores[j + 1] || 
        scores[j] == scores[j + 1] && (strcmp(teams[j], teams[j + 1]) > 0))
      {
        // swap score
        int tmp = scores[j];
        scores[j] = scores[j + 1];
        scores[j + 1] = tmp;
        
        // Swap teams
        char tmp_team[10];
        strcpy(tmp_team, teams[j]);
        strcpy(teams[j], teams[j + 1]);
        strcpy(teams[j + 1], tmp_team);
      }
    }
  }

  // print MOST TEAM
  for(int i = 0; i < n; i++)
  {
    printf("%d. %s %d\n", i+1 , teams[i], scores[i]);
  
  }


  return 0;
}
