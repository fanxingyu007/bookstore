
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include<algorithm>


using namespace std;
void trim(string &s)  //delete ""
{
    /*
     if( !s.empty() )
     {
     s.erase(0,s.find_first_not_of(" "));
     s.erase(s.find_last_not_of(" ") + 1);
     }
     */
    int index = 0;
    if( !s.empty())
    {
        while( (index = s.find('\"',index)) != string::npos)
        {
            s.erase(index,1);
        }
    }
    
}

float weight_year, weight_price, weight_feedback;
class interBooks
{
public:
    int id;
    string author;
    string bookname;
    string publishtime;
    string category;
    float currentprice;
    float feedback;
};

class Books{// class department
public:
    string bookname;
    string category;
    string publishtime;
    string author;
    string version;
    float currentprice;
    float originalprice;
    float feedback;
    string url;
};

class CBooks{// class department
public:
    string book_name;
    string author;
    int currentprice;
    int feedback;
    int id;
};

CBooks Newbooks[30000];

int readfromcsv(string filename, Books Amazon[20000])   //   read file from csv
{
    ifstream fin(filename);
    string line;
    int i=0;
    while (getline(fin, line))
    {
        if(line.length()==0)
            return i;
        istringstream sin(line);
        vector<string> fields;
        string field;
        while (getline(sin, field, ','))
        {
            fields.push_back(field);
        }
        trim(fields[0]);
        Amazon[i].bookname = fields[0];
        trim(fields[1]);
        Amazon[i].category= fields[1];
        trim(fields[2]);
        Amazon[i].publishtime= fields[2];
        trim(fields[3]);
        Amazon[i].author= fields[3];
        trim(fields[4]);
        Amazon[i].version= fields[4];
        trim(fields[5]);
        float current_int = atof(fields[5].c_str());
        Amazon[i].currentprice = current_int;
        trim(fields[6]);
        float original_int = atof(fields[6].c_str());
        Amazon[i].originalprice = original_int;
        trim(fields[7]);
        float feed_int = atof(fields[7].c_str());
        Amazon[i].feedback = feed_int;
        Amazon[i].url= fields[8];
        i++;
    }
    return 0;
}
float weight(interBooks Books[100],int o)
{
    int id=0;
    if(o==0)
    {
        return id;
    }
    else
    {
        for(int i=0;i<o;i++)
        {
            string year;
            string time;

            float weight;
            float final_weight=0;
            time = Books[i].publishtime;
            char* pch;
            const char *p=time.c_str();
            char temp[100];
            strcpy(temp,p);
            cout<<temp<<endl;
            pch = strtok (temp,"-");
            while (pch != NULL)
            {
                year = pch;
                pch = strtok (NULL, "-");
            }
            int m = std::stoi (year,nullptr,0);
            weight= weight_year*m+weight_price*(19.- Books[i].currentprice)+weight_feedback*Books[i].feedback;
            if(weight>final_weight)
            {
                final_weight=weight;
                id=Books[i].id;
            }
            
        }
        return id;
    }
}
int main()
{

    ofstream outfile;
    outfile.open("/Users/xue/final.csv",ios::out);
//    for(int i= 0;i<10000;i++)
//        cout<<Amazons[i].feedback<<endl;
    Books *Amazons = new Books[10000];
    int capacity_ama;
    string store="/Users/xue/Documents/xcode_test/540/fff/fff/Amazon.csv";
    capacity_ama=readfromcsv(store, Amazons);
    cout<<capacity_ama<<endl;
    Books *BooksB = new Books[10000];
    int capacity_B;
    string store1="/Users/xue/Documents/xcode_test/540/fff/fff/BooksB.csv";
    capacity_B=readfromcsv(store1, BooksB);
    
    Books *Million=new Books [10000];
    int capacity_Mill;
    string store2="/Users/xue/Documents/xcode_test/540/fff/fff/booksmillion.csv";
    capacity_Mill=readfromcsv(store2, Million);
    //    for(int i= 0;i<10000;i++)
    //        cout<<Amazons[i].feedback<<endl;
    Books *wholetable=new Books[35000];
    for(int i=0; i<10000;i++)
    {
        wholetable[i].bookname=Amazons[i].bookname;
        wholetable[i].author=Amazons[i].author;
        wholetable[i].publishtime=Amazons[i].publishtime;
        wholetable[i].currentprice=Amazons[i].currentprice;
        wholetable[i].feedback=Amazons[i].feedback;
        wholetable[i].category=Amazons[i].category;
    }
    delete [] Amazons;
    int j=0;
    for(int i=10000; i<20000;i++)
    {
        wholetable[i].bookname=BooksB[j].bookname;
        wholetable[i].author=BooksB[j].author;
        wholetable[i].publishtime=BooksB[j].publishtime;
        wholetable[i].currentprice=BooksB[j].currentprice;
        wholetable[i].feedback=BooksB[j].feedback;
        wholetable[i].category=BooksB[j].category;
        j++;
    }
    delete [] BooksB;
    int kk=0;
    for(int i=20000; i<30000;i++)
    {
        wholetable[i].bookname=Million[kk].bookname;
        wholetable[i].author=Million[kk].author;
        wholetable[i].publishtime=Million[kk].publishtime;
        wholetable[i].currentprice=Million[kk].currentprice;
        wholetable[i].feedback=Million[kk].feedback;
        wholetable[i].category=Million[kk].category;
//        cout<<kk<<" "<<Million[kk].bookname<<endl;
        kk++;
    }
    delete [] Million;
//    for(int h=25000;h<30000;h++)
//        cout<<wholetable[h].bookname<<endl;
    interBooks mid[30000];
    int k=0;
    int q=0;
    int co;
    //    int nn=0;
    cout<<1111<<endl;
    int count=0;
    
    for(int i=0;i<30000;i++)
    {
        interBooks *inter=new interBooks[3000];
        int o=0;
        for(k=0;k<q;k++)
        {
            if(mid[k].bookname==wholetable[i].bookname)
            {
//                cout<<"已经出现"<<endl;
                k=k-1;
                break;
            }
        }
        //        cout<<k<<"  "<<q<<endl;
        if(k!=q)
        {
//                                    cout<<"跳过"<<endl;
            continue;
            //                        cout<<"没调"<<endl;
        }
//        count++;
        for(int j=0;j<30000;j++){
  //          cout<<"进入循环"<<endl;
            if(wholetable[i].bookname==wholetable[j].bookname && wholetable[i].author==wholetable[j].author&&wholetable[j].bookname!="")
            {
//                cout<<"进入if"<<o<<endl;
                //                cout<<1<<endl;
                //                                cout<<"相同"<<endl;
                inter[o].id=j;
                inter[o].author=wholetable[j].author;
                inter[o].publishtime=wholetable[j].publishtime;
                inter[o].category=wholetable[j].category;
                inter[o].bookname=wholetable[j].bookname;
                inter[o].currentprice=wholetable[j].currentprice;
                inter[o].feedback=wholetable[j].feedback;
   //             cout<<Newbooks[o].id<<endl;
                o++;
//                cout<<o<<endl;
            }
            co=o;
        }
 //       cout<<"o：："<<co<<endl;
        int id;
        for(int s=0;s<co;s++)
        {
            string year;
            string time;
            float weight;
            float final_weight=0;
            time = inter[s].publishtime;
            char* pch;
            const char *p=time.c_str();
            char temp[100];
            strcpy(temp,p);
//               cout<<temp<<endl;
            pch = strtok (temp,"-");
            while (pch != NULL)
            {
                year = pch;
                pch = strtok (NULL, "-");
            }
            float m = atof(year.c_str());
            id=inter[s].id;
            inter[s].publishtime=year;
            weight= weight_year*m+weight_price*(19.- inter[s].currentprice)+weight_feedback*inter[s].feedback;
            if(weight>final_weight)
            {
                final_weight=weight;
                id=inter[s].id;
            }
        }
        int mm;
        mm=id;
   //     cout<<"循环"<<m<<endl;
        for(int d=0;d<co;d++)
        {
            if(inter[d].id==mm)
            {
                count++;
//            cout<<inter[d].currentprice;
//            cout<<count<<"写入数据："<<d<<"  "<<co<<"  "<<m<<endl;
            outfile<<inter[d].bookname;
            outfile<<",";
            outfile<<inter[d].author;
            outfile<<",";
            outfile<<inter[d].currentprice;
            outfile<<",";
            outfile<<inter[d].feedback;
            outfile<<",";
            outfile<<inter[d].category;
            outfile<<",";
            outfile<<inter[d].publishtime;
            outfile<<",";
            outfile<<inter[d].id;
            outfile<<"\n";
            }
        }
        if(o>0)
        {
//            cout<<q<<"列表加一"<<endl;
            mid[q].bookname=wholetable[i].bookname;
            q++;
        }
        //        delete [] wholetable;
        delete [] inter;
    }
    cout<<count<<endl;
}










