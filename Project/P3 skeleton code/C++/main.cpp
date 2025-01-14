#include <iostream>
#include<sstream>
#include<fstream>

#include "HashTable.hpp"
#include "HeapPriorityQueue.hpp"

using namespace std;

ifstream inputfile;
ofstream outputfile;

void read_part_1()
{
   HashTable<int> table = HashTable<int>(2);
   int lineNum = -1;
   inputfile >> lineNum;
   while (lineNum--) {
      char c;
      inputfile >> c;
      // cout << "enter" << endl;
      if (c == 'p') {
         // cout << "Before put" << endl;
         // table.print();
         string k;
         inputfile >> k;
         int v;
         inputfile >> v;
         int r = table.put(k, v);
         if (r == -100) {
            outputfile << "null" << endl;
         }
         else {
            outputfile << r << endl;
         }
         // cout << "After put" << endl;
         // table.print();
      }
      if (c == 'g') {
         string k;
         inputfile >> k;
         // cout << "get " << k << endl;
         int r = table.get(k);
         if (r == -100) {
            outputfile << "null" << endl;
         }
         else {
            outputfile << r << endl;
         }
      }
      if (c == 'r') {
         // cout << "Before replace" << endl;
         // table.print();
         string k;
         inputfile >> k;
         int v;
         inputfile >> v;
         int r = table.replace(k, v);
         if (r == -100) {
            outputfile << "null" << endl;
         }
         else {
            outputfile << r << endl;
         }
         // cout << "After replace" << endl;
         // table.print();
      }
      if (c == 's') {
         outputfile << table.size() << endl;
      }
      if (c == 'c') {
         string k;
         inputfile >> k;
         if (table.contains(k)) {
            outputfile << 1 << endl;
         }
         else {
            outputfile << 0 << endl;
         }
      }
      if (c == 'm') {
         int i;
         inputfile >> i;
         outputfile << table.getCollision(i) << endl;
      }
      if (c == 'd') {
         string k;
         inputfile >> k;
         int r = table.remove(k);
         if (r == -100) {
            outputfile << "null" << endl;
         }
         else {
            outputfile << r << endl;
         }
      }
   }
}

void read_part_2()
{
   //TODO: Part 2: Anagrams
}

void read_part_3()
{
   HeapPriorityQueue<int> heap = HeapPriorityQueue<int>(0);
   int lineNum = -1;
   inputfile >> lineNum;
   while (lineNum--) {
      char c;
      inputfile >> c;
      cout << c << endl;
      // cout << "enter" << endl;
      if (c == 'i') {
         // cout << "Before put" << endl;
         // table.print();
         int v;
         inputfile >> v;
         heap.insert(v);
         // cout << "After put" << endl;
         // table.print();
      }
      if (c == 'r') {
         heap.removeMin();
      }
      if (c == 'm') {
         cout << "enter" << endl;
         int r = heap.min();
         cout << r << endl;
         if (r == 0) {
            outputfile << "empty" << endl;
         }
         else {
            outputfile << r << endl;
         }
      }
      if (c == 's') {
         int size = heap.size();
         int list[heap.size()];
         int index = 0;
         while (!heap.empty()) {
            list[index] = heap.min();
            heap.removeMin();
            index ++;
         }
         for (int i = 0; i < size; i++) {
            outputfile << list[i] << endl;
         }
      }
   }
}


int main(int argc, char *argv[])
{
   //Read in the test case


   inputfile.open(argv[1]);
   outputfile.open(argv[2]);

   string str;

   getline(inputfile, str);
   int part;
   stringstream convert(str);
   convert >> part;

   switch(part)
   {
       case 1:
           read_part_1();
           break;
       case 2:
           read_part_1();
           break;
       case 3:
           read_part_3();
           break;
   }

   inputfile.close();
   outputfile.close();
   
   return 0;
}

