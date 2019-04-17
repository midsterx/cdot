#include<bits/stdc++.h>
#include<ctype.h>
using namespace std;

class quadruple
{

public:

  vector< vector<string> > table;

  void show_table()
  {
            cout << "operator" << "      " << "arg1" << "       " << "arg2" <<"          " << "result" << endl;
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table[i].size(); j++)
        {
            if(table[i][j]=="ifFalse") cout << table[i][j] << "        ";
            else if(table[i][j]=="param" || table[i][j]=="call" ) cout << table[i][j] << "        ";
            else cout << table[i][j] << "             ";
        }
        cout << endl;
    }
    cout << endl;
  }


};

quadruple create_quadruples(string filename)
{
  quadruple q;

  ifstream fp(filename);
  string line;

  while(getline(fp,line))
  {

    bool isparam = line.find("param") != string::npos;
    bool iscall = line.find("call") != string::npos;

    vector<string> operations = {
                                 "+" , "-" ,
                                 "*" , "/" ,
                                 "<" , ">" ,
                                 "<=" , ">=",
                                 "=="
                               };
    bool isassignwithoperation = false;
    for(int i=0 ; i<operations.size(); i++)
    {
      if(line.find(operations[i]) !=string::npos == true)
      {
        isassignwithoperation = true;
        break;
      }
    }

    bool isassign=false;
    if(isassignwithoperation==false and  line.find("=") != string::npos )
      isassign=true;

    bool islabel = line.find(":") != string::npos;


    bool isconditional = line.find("if") !=string::npos;
    bool isunconditionalgoto=false;
    if(isconditional==false and  line.find("goto") != string::npos )
      isunconditionalgoto=true;



    //<======================================== PARSING ICG ================================>
    if(isparam)
    {
        stringstream instruction(line);
        string p1 ,p2;
        instruction >> p1 >> p2;
        vector<string> v {p1 , p2 , "  " , "  "};
        q.table.push_back(v);
    }

    else if(iscall)
    {
      stringstream instruction(line);
      string p1,eq,p2,p3,p4;
      instruction >> p1 >> eq >> p2 >> p3 >> p4;
      vector<string> v {p2 , p3 , p4 , p1};
      q.table.push_back(v);
    }

    //res = arg1 ops arg2
    else if(isassignwithoperation)
    {
        stringstream instruction(line);
        string p1,eq,p2,p3,p4;
        instruction >> p1 >> eq >> p2 >> p3 >> p4;
        vector<string> v {p3 , p2 , p4 , p1};
        q.table.push_back(v);
    }

    //res = arg1
    else if(isassign)
    {
      stringstream instruction(line);
      string p1,eq,p2;
      instruction >> p1 >> eq >> p2;
      vector<string> v {eq , p2 ,"  ", p1};
      q.table.push_back(v);
    }

    //L1:
    else if(islabel)
    {
      stringstream instruction(line);
      string p1;
      instruction >> p1;
      vector<string> v {"label" ,"","", p1};
      q.table.push_back(v);
    }

    else if(isconditional)
    {
      stringstream instruction(line);
      string p1,p2,p3,p4;
      instruction >> p1 >> p2 >> p3 >> p4;
      vector<string> v {p1 ,p2,"", p4};
      q.table.push_back(v);
    }

    else if(isunconditionalgoto)
    {
      stringstream instruction(line);
      string p1,p2;
      instruction >> p1 >> p2;
      vector<string> v {p1 ,"","", p2};
      q.table.push_back(v);
    }


  }
    q.show_table();

  return q;
}

int eval(string arg1 , string op , string arg2)
{
    if(op == "+") return stoi(arg1) + stoi(arg2);
    else if(op == "-") return stoi(arg1) - stoi(arg2);
    else if(op == "*") return stoi(arg1) * stoi(arg2);
    else if(op == "/") return stoi(arg1) / stoi(arg2);

}

quadruple constant_propogate( quadruple q , int i)
{
  string var = q.table[i][3];
  string val = q.table[i][1];

  for(int index = i+1 ; index < q.table.size() ; index++)
  {
      if(q.table[index][3] == var)return q;

      else if(q.table[index][2] == var ) q.table[index][2]=val;
      else if(q.table[index][1] == var ) q.table[index][1]=val;

  }

  return q;
}

quadruple constant_optimize(quadruple q)
{
  for(int i = 0; i < q.table.size(); i++)
  {
      //got one instruction (a = 2 * 3)
      bool is_const_expr = false;
      if(isdigit(q.table[i][1][0]) && isdigit(q.table[i][2][0])) is_const_expr=true;

      if(is_const_expr)
      {
        int res = eval(q.table[i][1] , q.table[i][0] , q.table[i][2]);
        q.table[i][0] = "=";
        q.table[i][1] = to_string(res);
        q.table[i][2] = " ";

        //propogate this constant value ahead until next occurence
        q = constant_propogate(q,i);
      }

      //a=100
      else if((isdigit(q.table[i][1][0]) && q.table[i][0]=="="))q = constant_propogate(q,i);

  }
  return q;
}



int main()
{
  //instantiate the table
  cout << "QUADRUPLE TABLE" << endl;
  quadruple q = create_quadruples("output");

  //CODE OPTIMIZATION

  //phase 1 : constant folding
  cout << "AFTER CONSTANT FOLDING AND PROPAGATION" << endl;
  quadruple q_const_folded = constant_optimize(q);
  q_const_folded.show_table();



}
