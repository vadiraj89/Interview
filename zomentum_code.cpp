#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;

string getKey (string & str)
{
  int arr[str.length ()];

  arr[0] = 0;

  int len = str.length ();

  for (int i = 1; i < str.length (); i++)
    {
      if (str[i] >= str[i - 1])
	    {
	        arr[i] = str[i] - str[i - 1];
	    }
      else
	    {

	    arr[i] = 'z' - str[i - 1] + str[i] - 'a' + 1;
	    }
    }

  string key = to_string (len) + "#";

  for (int i = 1; i < str.length (); i++)
    {

      key = key + to_string (arr[i]) + "#";

    }
  

  return key;
}


int main ()
{
    vector<string> words ;
  
    string word;
  
    #ifndef ONLINE_JUDGE
  
    freopen("input.txt","r",stdin);
  
    while (cin >> word) 
        { 
            words.push_back(word); 
        } 
    
    freopen("output.txt","w",stdout);
    
    #endif 
     
 
    unordered_map < string, vector < int >>Hash;


    for (int i = 0; i < words.size(); i++)
    {
        string key = getKey (words[i]);
        Hash[key].push_back (i);
    }


    for (auto it = Hash.begin (); it != Hash.end (); it++)
        {
            for (auto v = (*it).second.begin (); v != (*it).second.end (); v++)
	        cout << words[*v] << ", ";
	    
            cout << endl;
        }
   
  return 0;
}
