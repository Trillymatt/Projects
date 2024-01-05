//Matthew Norman 1001750240
#include "DrawTool.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    //initialize variables and map
    char map[MAXMAPSIZE][MAXMAPSIZE];
    int mapSize;
    char delimiters[] = "(),";
    char command[100];
    bool exitFlag = true;
    InitializeMap(map, &mapSize);
    //print instructions
    PrintInstructions();

    //start of loop
    while (exitFlag)
    {
        //print map and ask for draw command
        PrintMap(map, mapSize);
        printf("Enter draw command (enter Q to quit): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0;
        //tokenize drawCommands
        char *token = strtok(command, delimiters);
        if(token == NULL)
        {
            printf("No command entered.\n");
        }
        else
        {
            char drawCommand = toupper(token[0]);
            //if Q is entered get out of loop
            if(drawCommand == 'Q')
            {
                exitFlag = false;
            }
            else
            {
                //give the drawCommand to differnt variables
                int row = atoi(strtok(NULL, delimiters));
                int col = atoi(strtok(NULL, delimiters));
                int count = atoi(strtok(NULL, delimiters));            
                char *markToken = strtok(NULL, delimiters);
                char mark = markToken ? *markToken : 'X';
                //make sure that these varibales have values
                if(row >= 0 && row < MAXMAPSIZE && col >= 0 && col < MAXMAPSIZE)
                {
                    //do as draw command ask
                    switch (drawCommand)
                    {
                    case 'P':
                        map[row][col] = mark;
                        break;
                    case 'H':
                        DrawLine(map, row, col, drawCommand, count, mark);
                        break;
                    case 'V':
                        printf("%d, %d, %c, %d, %c", row, col, drawCommand, count, mark);
                        DrawLine(map, row, col, drawCommand, count, mark);
                        break;
                    default:
                        printf("That draw command is unknown. \n");
                        break;
                    }
                }
                //error catching
                else
                {
                    printf("Row or column out of bounds.\n");
                }
            }
        }
    }   
    return 0;
}