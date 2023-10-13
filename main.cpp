
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Sales{
public:
string date;
string region;
string rep;
string item;
int units;
float unitCost;
float total() {return units*unitCost;}
  
};

void simpleSortTotal(Sales*, int c);

int main() {
string num;
string line;
ifstream infile;
int   salesArrayCount = 0;
Sales* s;
s = new Sales[40];


  cout << "Record: OrderDate, Region, Rep, Item, Units, UnitCost, Total\n";
		infile.open ("SalesDataDyn.csv", ifstream::in);
		if (infile.is_open())
		{
    getline(infile,line);
		int   c=0;
		while (getline(infile,line)){
      stringstream str(line);
      Sales x;
			getline(str, x.date, ',');
			getline(str, x.region, ',');
			getline(str, x.rep, ',');
			getline(str, x.item, ',');
		  getline(str,num, ',');
			x.units = stoi(num);
			getline(str, num, '\n');
			x.unitCost = stof(num);
      s[c] = x;
			c++;
		}
  salesArrayCount = c;
    infile.close();
}
  

  simpleSortTotal(s, salesArrayCount);
  
for (int i=0; i < salesArrayCount; i++)
		cout << "Record: "<< s[i].date <<"," << s[i].region << "," << s[i].rep << "," << s[i].item << ", " << s[i].units << ", " << s[i].unitCost << ", " << s[i].total() << endl;
  
}

void simpleSortTotal( Sales* sales, int c)
{
	
	for (int i=0; i < c; i++)
		for (int j=i; j < c; j++)
		if (sales[i].total() > sales[j].total())
		{
      Sales temp;
      temp = sales[i];
      sales[i] = sales[j];
      sales[j] = temp;
			
		}
} 