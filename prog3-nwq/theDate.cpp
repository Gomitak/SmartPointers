#include "theDate.h"
#include <iostream>
# include <string.h>

theDate::theDate(){
	day = 0;
	month = 0;
	year = 0;
}

theDate::theDate(int tday, int tmonth, int tyear){
	day = tday;
	month = tmonth;
	year = tyear;
}