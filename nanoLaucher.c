/*

objectives :

if nothing > open last acessible
if name and exist > open
if name and not exist > enhanced create
if -h > open 1 before last
if -h [0-9]+ > open n bafore last
if -H > show history + choice

+ : no duplicates
+ : clean history in bg

*/

# include <stdio.h>
# include <string.h>

int main(void)
{

  // initialisation
  int i=0, k=0, searchIndex, match=0;
  char line[1000], valid[1000][1000], path[1000][1000];
  FILE *nanoHistory = fopen("/data/data/com.termux/files/home/.temp/last/nano", "r");
  if (nanoHistory == NULL) { return 0; }

  // get array out of nano history
  while (fgets (line, 1000, nanoHistory) != NULL)
  {
    line[strcspn(line, "\n")] = 0;
    strcpy(path[i], line);
    i++;
  }
  fclose(nanoHistory);

  // check file paths
  for(int j=0; j < i; j++)
  {
    FILE* testHistory = fopen(path[j], "r");
    if(testHistory)
    {
      fclose(testHistory);
      strcpy(valid[k], path[j]);
      k++;
    }
  }
  k--;

  // sort them
  int size = k;
  for(; k != -1; k--)
  {
    searchIndex = size - k;
    for(; searchIndex != -1; searchIndex--)
    {
      printf("POS: %d > %s | COMPARING WITH: %d > %s\n", k, valid[k], searchIndex, valid[searchIndex]);
      if(valid[k] == valid[searchIndex])
      {
        match = 1;
        break;
      }
    }
    if (match == 1)
    {
      match = 0;
      printf("HIT: %s\n", valid[k]);
    }
    puts("------------------------------");
  }

  return 0;

}
