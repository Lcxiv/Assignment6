/*
Condevaux Louis
2305172
Assignment 6
Rene German
Session 1
 */

#ifndef SORTING_H
#define SORTING_H

#include <iostream>
class Sorting
{
public:
  Sorting();
  ~Sorting();

  void bubbleSort(float *myArr, int n);
  void selectionSort(float *myArr, int n);
  void insertionSort(float *myArr, int n);
  void merge(float *myArr, int l, int m, int r);
  void mergeSort(float *a, int start, int end);
  void quickSort(float *myArr, int left, int right);

  void readFile(std::string nameF);
  void randomSort(int n);
  void print(float *myArr);
  void totalSort(int n);
  void generateRandomList(std::string file,int n);
  int partition(float *myArr, int left, int right);
  void exportSorted(int n);


  float *arrMerge;
  //float *myArrayB;
  float *arrBubble;
  float *arrSelection;
  float *arrInsertion;
  float *arrQuick;
  //merge or quick sort
};
#endif
