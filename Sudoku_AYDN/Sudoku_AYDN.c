#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENTGH 150

//-------- conditions -------
void cond(void);
//-------- menues and taking selection -------
int menu(void);
int submenu(void);
void take_mode(int mode);
void read_arr(void);

//-------- panel and game works --------
void g_panel(void);
void play_game(void);
void values_to_panel(void);
void print_panel(void);
int load_game(char Fpath[MAX_LENTGH]);

//-------- control process -------
int cont_func(void);
int mx_check(char arr[9][9]);

//-------- saving procedures -------
void save_game(char Fpath[MAX_LENTGH]);

char values[9][9];
char pnl[19][37];
// the panel of sudoku table; (pnl)

int main(){
    cond();
	g_panel();

    /*
    -> we get selection form user (main menu)
    */
	int dt=1;
	do
	{
		int selection=menu();
		switch (selection){
			case (1):{
				
				int gmode=submenu();
				if(gmode ==1 || gmode ==2 || gmode ==3 ){
					take_mode(gmode);
					play_game();

				}
				else{
					printf("\n You do not enter accepted value... Please restart the program");
					dt = 0;
				}

				break;
			}
	
			case (2):{
                int start;

                char filepath1[MAX_LENTGH];
				printf("// load game section \n\nPlease enter your file name for loading your game (with extension of file):: ");
                scanf("%s", &filepath1);
                // -> burada save sistemi devreye girecek, global alanda dosya ismi verilir, oradan fonskyon içinde kullanırız.
			    if (filepath1[strlen(filepath1) - 1] == '\n'){
        	    	filepath1[strlen(filepath1) - 1] = '\0';
    		    }
			    // filePapth verirken fonksiyon içinde bir kayıt tutarken, fgets gets problem yaşattı.
                // ya eski usul getchar ile karakter karakter sağlatacağım ya da zaten pathte boşluk olmayacağı için bu iş sağlanmış olacaktır.
                start = load_game(filepath1);
                if(start==1){
                    play_game();
                }
                else{
                    printf("\n\n>>> ERROR - you make a mistake on loading filepath\n>>> Please check your file path, and restart the game...\n\n");
                    dt = 0;
                }
                
				break;
			}
				
			case (3):{
				dt = 0;
				printf("\n:::: see you later!!! ::::");
				break;
			}
				
			default:{
				printf("\n You do not enter accepted value... Please restart the program");
				dt = 0;
				break;
			}
		}
	}while (dt !=0);
	
	return 0;
}


int menu(void){
	int slc;

	printf("\n*-*-*-*-*-*-*-* Welcome to Sudoku Game  *-*-*-*-*-*-*-*-*-*");
	printf("\n*              Please Press                               *");
	printf("\n*              1 - Play New Game                          *");
	printf("\n*              2 - Load previous Game                     *");
	printf("\n*              3 - Quit                                   *");
	printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("\nYour selection :: ");
	scanf("%d", &slc);
	
	return slc;
}

int submenu(void){
	int slc;

	printf("\n*-*-*-*-*-*-*-*-*-*-*-*-* Game Mode *-*-*-*-*-*-*-*-*-*-*-*-*");
	printf("\n*              Please Press                                 *");
	printf("\n*              1 - Easy                                     *");
	printf("\n*              2 - Medium                                   *");
	printf("\n*              3 - Hard                                     *");
	printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("\nYour selection :: ");
	scanf("%d", &slc);
	
	return slc;
}


void take_mode(int mode){
    FILE *fptr;
    
    char ch;
	char filename[MAX_LENTGH];
    
    /*
    -> Before the execute the program, please enter your filepath of folder that include  easy,medium,hard.txt;
        Here an examples :: C:\\Users\\Talha\\Desktop\\WORK-T (ACADEMIC)\\C - workings\\C-Homework\\Homework-2\\
    */
    char modepath[] = "C:\\Users\\Talha\\Desktop\\WORK-T (ACADEMIC)\\C - workings\\C-Homework\\Homework-2\\";
    int i=0;
    int j=0;
	if(mode ==1){
        strcat(modepath,"easy.txt");
		fptr = fopen(modepath,"r");
	}
	else if(mode == 2){
        strcat(modepath,"medium.txt");
		fptr = fopen(modepath,"r");
	}
	else if(mode == 3){
        strcat(modepath,"hard.txt");
		fptr = fopen(modepath,"r");
	}

	else{
		printf("\nyour entered value is not acceptable Please try again");
	}


    if(fptr == NULL){
        printf("\n we can not reach to file // ERROR");
    }

    else{
        printf("\nGame Succesfully entegreting the panel, ENJOY!!!\n");
        do{
            ch = getc(fptr);
            if(ch =='\n'){
                i++;
                j=0;

            }

			// we add the else if condiiton for not add the 'space' chrachter inside of values array.
			else if(ch == ' '){
				continue;
			}
            else{
                values[i][j] = ch;
                j++;

            }
        }while(!feof(fptr));
    }
    fclose(fptr);
}

void read_arr(void){
	printf("\n");
    int i,j;

    for(i=0;i<9;i++){
        for (j=0; j<9; j++){
            printf("%4c",values[i][j]);

        }
        printf("\n");
    }

}
void g_panel(void){
    // we use modular and condition combinations to creating sudoku game panel here.

    int i,j;

    for(i=0;i<19;i++){
        for(j=0;j<37;j++){
            if(i%2==0){
                if(j%4==0){
                    pnl[i][j] = '+';

                }
                else if((i==0 || i== 18) && j%4!=0){
                    pnl[i][j] = '=';
                }
                else{
                    pnl[i][j] = '-';
                }


            }

            else{
               if(j%4==0 && j%13==0 ){
                    pnl[i][j] = '|';

                }
                else if(j%4==0 && j%13!=0){
                    pnl[i][j] = ':';
                }
                /*-------------------*/
                else if(j%4==2){
                    pnl[i][j] = 'k';
                }

                /*------------------*/
                else{
                    pnl[i][j] = ' ';
                }

            }
        }
    }

}

void play_game(void){
    int check;
    char row,column,value;
    int row_p,column_p,j;
	char filepath[MAX_LENTGH];
    values_to_panel();

    do {
        printf("\n>> whenever you save the game, please enter s or S on value");
        print_panel();
        printf("\nPlease enter the Column:: ");
        scanf(" %c",&column);
        printf("\nPlease enter the Row:: ");
        scanf(" %c",&row);
        printf("\nPlease enter the value:: ");
        scanf(" %c",&value);
        if(value == 's' || value == 'S' || row == 's' || row == 'S' || column == 's' || column == 'S'){
            printf("The game saving ....\n\nPlease enter your file name(with extension of file):: ");
            scanf("%s", &filepath);
            // -> file save function will work here.
			if (filepath[strlen(filepath) - 1] == '\n'){
        		filepath[strlen(filepath) - 1] = '\0';
    		}
			// I have some troubles with fgets and gets suppose i use scanf // so be careful giving your saving file name // not put space between chrachters.
			
			save_game(filepath);
            break;
        }

        else{
            row_p = row - '0';
            printf("%d", row_p);
            column_p = column - '0';
            printf("\n%d", column_p);
        }

        switch (column)
        {
            case ('1'):{
                j= 2;
                break;
            }
                
            case ('2'):{
                j= 6;
                break;
            }
                
            case ('3'):{
                j= 10;
                break;
            }
                
            case ('4'):{
                j= 14;
                break;
            }
                
            case ('5'):{
                j= 18;
                break;
            }
                
            case ('6'):{
                j= 22;
                break;
            }
                
            case ('7'):{
                j= 26;
                break;
            }
                
            case ('8'):{
                j= 30;
                break;
            }
                
            case ('9'):{
                j= 34;
                break;
            }
                
            default:{
                printf("\n\nyour input value is not in accepted format\nPlease enter the value between (1-9)");
                break;
            }
        }

        if(value>= '1' && value<= '9' ){
            pnl[(2*row_p)-1][j] = value;
            values[row_p-1][column_p-1] = value;
        }

        //--------------------------------------------
        /*
            -> Here, control system is ON.
            - if all column and row is full now hint is go to open and give a hint to user.
            The mission of control function is that;
            
        */
        check = cont_func();
        

    }while(check !=1);
}

void values_to_panel(void){
    int i,j,col;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            switch (j+1)
            {
                case (1):{
                    col= 2;
                    break;
                }
                    
                case (2):{
                    col= 6;
                    break;
                }
                    
                case (3):{
                    col= 10;
                    break;
                }
                    
                case (4):{
                    col= 14;
                    break;
                }
                    
                case (5):{
                    col= 18;
                    break;
                }
                    
                case (6):{
                    col= 22;
                    break;
                }
                    
                case (7):{
                    col= 26;
                    break;
                }
                    
                case (8):{
                    col= 30;
                    break;
                }
                    
                case (9):{
                    col= 34;
                    break;
                }
            }

            if(values[i][j] == '0'){
                pnl[(2*(i+1))-1][col] = ' ';
            }
            else{
                pnl[(2*(i+1))-1][col] = values[i][j];
            }
            
        }
    }
}

void print_panel(void){
    printf("\n");
    int i,j;

    for(i=0;i<19;i++){
        for(j=0;j<37;j++){
            printf("%c", pnl[i][j]);
        }
        printf("\n");
    }

    printf("\n------------------------\n");

}

void save_game(char Fpath[MAX_LENTGH]){
    FILE *fptr;
    char ch;
    
    int i=0;
    int j=0;

    fptr = fopen(Fpath,"w");
    if(fptr == NULL){
        printf("\n we can not reach to file // ERROR\n> Please check your filepath and do not uses escape charachter on your filename");
    }

    else{
        printf("\n>>>succesfully complete!\ngame saved on %s successfuly\n\n\n",Fpath);

        for(i=0;i<9;i++){
            for (j=0; j<9; j++){
                putc(values[i][j],fptr);
                putc(' ',fptr);

            }
            putc('\n',fptr);
        }
    }
    fclose(fptr);
}

int cont_func(void){
    int i,j,k,a,fn,chs;

    // fn value giving refer to return value; so when we have not any zeros on values array, the print function start to work, 
    int ch_row[9] = {0};
    int ch_column[9] = {0};
    char check_mx[9][9];
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            check_mx[i][j] = '*';
        }
    }

    int counter = 0;
    int row_s = 0;
    int column_s =0;
    int check = 0;
    fn = 0;


    // check the rows 
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            ch_row[j] = values[i][j] - '0';

        }
        

        for(k=1;k<10;k++){
        // we examine whole numbers except zero - that refers to <space>
            counter = 0;

            for(a=0;a<9;a++){
                if(ch_row[a] == k){
                    
                    counter++;
                    if(counter >1){
                        check_mx[i][a] = 'x';
                        
                    }
                }

                if(ch_row[a] == 0){
                    check_mx[i][a] = ' ';
                }
            }
        }
        
    }

    printf("\n");
    //////////////////////////////////////////////////////////
    printf("\n");
    
    // check columns
    for(j=0;j<9;j++){
        for(i=0;i<9;i++){
            ch_column[i] = values[i][j] - '0';

        }
        

        for(k=1;k<10;k++){
        // we examine whole numbers except zero - that refers to <space>
            counter = 0;

            for(a=0;a<9;a++){
                
                if(ch_column[a] == k){
                    counter++;
                    if(counter >1){
                        check_mx[a][j] = 'x';
                        
                    }
                }
                if(ch_column[a] == 0){
                    check_mx[a][j] = ' ';
                }
            }
        }
        
    }
    chs = mx_check(check_mx);
    if(chs ==0){
        printf("\n----------------------------\n----------------------------\n\n\n");
        printf("CONGRULATIONS!!!  -  You finish the game, \n\nSudoku completed\n\n");
        return 1;

    }
    else{
        return 0;
    }
}

int mx_check(char arr[9][9]){
    int check,i,j,space;
    check =0;
    space = 0;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if((arr[i][j] == 'x')){
                check = 1;
                
            }
            if((arr[i][j] == ' ')){
                space =1;
            }
        }
    }

    if(check ==1 && space ==0){
        printf("\n\n// hint table only activated when you not have any empty cell // \n\n");
        printf("\n\n\n:: Please check your issues on the check table ::\n\n\n");

        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
              printf("%4c", arr[i][j]);
            }   
            printf("\n");
        }
        return 1;
    }
    else if(space ==1){
    }

    else{
        return 0;
    }
    
}

int load_game(char Fpath[MAX_LENTGH]){
    FILE *fptr;
    char ch;
    
    int i=0;
    int j=0;

    fptr = fopen(Fpath,"r");
    if(fptr == NULL){
        printf("\n we can not reach to file // ERROR");
        return 0;
    }

    else{
        printf("\n>>> Succesfully complete...\n>>> You can continue to your loaded game\n\n");
        do{
            ch = getc(fptr);
            if(ch =='\n'){
                i++;
                j=0;

            }
			
            // we add the else if condiiton for not add the 'space' chrachter inside of values array.

			else if(ch == ' '){
				continue;
			}
            else{
                values[i][j] = ch;
                j++;

            }
        }while(!feof(fptr));

    }
    fclose(fptr);
    
    return 1;
}

void cond(void){
    printf("Before the start to game please read that points\n\n - you must change your easy,medium,hard paths in specific filepath variable according to your filesystem\n - do not give spaces between charachters on filenames(when saving or loading processes)\n - the hint activated when you have not any empty cells on game screen\nThat is all... ENJOY!\n\n");
}