/*
Condevaux Louis
2305172
Assignment 6
Rene German
Session 1
 */

#include "Sorting.h"
#include <iostream>
#include <fstream>
#include "time.h"

/**
 * [Sorting::Sorting is a class that returns the time of different sorting algorithms]
 */
using namespace std;

Sorting::Sorting(){}

Sorting::~Sorting()
{
  delete [] arrMerge;
  //delete [] myArrayB;
  delete [] arrBubble;
  delete [] arrInsertion;
  delete [] arrQuick;
  delete [] arrSelection;
  //cout << "Arrays deleted." << endl;
}

/**
 * [Sorting::bubbleSort algorithm]
 * @param myArr [takes an array of floats]
 * @param n     [size of the array]
 */
void Sorting::bubbleSort(float *myArr, int n)
{
  //cout << "Bubble Sort Algorithm." << endl;
  float temp = 0;
  for (int i = 0; i < n; ++i)
  {

  	for (int j = 0; j < n-1;++j)
  	{
  		if (myArr[j] > myArr[j+1])
  		{
  			temp = myArr[j+1];
  			myArr[j+1] = myArr[j];
  			myArr[j] = temp;
  		}
  	}
  }
//print(arrBubble);
}

/**
 * [Sorting::selectionSort algorithm]
 * @param myArr [takes an array of floats]
 * @param n     [the size of the array]
 */
void Sorting::selectionSort(float *myArr, int n)
{
  //cout << "Selection Sort Algorithm." << endl;

  int minIndex;
  float tmp;
  for (int i = 0; i < n-1; i++)
  {
		minIndex = i;
		for (int j = i + 1; j < n; j++){
		  if (myArr[j] < myArr[minIndex])
			   minIndex = j;
    }
    if (minIndex != i)
    {
      tmp = myArr[i];
      myArr[i] = myArr[minIndex];
      myArr[minIndex] = tmp;
    }
	}
  //print(myArr);

}

/**
 * [Sorting::insertionSort algorithm]
 * @param myArr [takes an array of floats]
 * @param n     [size of the array]
 */

void Sorting::insertionSort(float *myArr, int n)
{
  //cout << "Insertion Sort Algorithm." << endl;
  //int *myArr;
  float temp;
  int k;
	for (int j = 0; j < n; ++j) //marker
	{
	  temp = myArr[j]; //store marked item
		k = j;
		while (k > 0 && myArr[k-1] >= temp) //while the thing to the left is larger, shift
		{
			myArr[k] = myArr[k-1];
			--k;
		}
		myArr[k] = temp; //put marked item in right spot
    //cout << myArr[j] << endl;
	}
  //print(myArr);

}

/**
 * [Sorting::randomSort Creates a random array]
 * @param n [size of the array]
 */
void Sorting::randomSort(int n)
{
  arrMerge = new float[n];
  //myArrayB = new float[n];
  arrBubble = new float[n];
  arrSelection = new float[n];
  arrInsertion = new float[n];
  arrQuick = new float[n];
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    float z = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/n));
    arrMerge[i] = z;
    //myArrayB[i] = z;
    arrBubble[i] = z;
    arrSelection[i] = z;
    arrInsertion[i] = z;
    arrQuick[i] = z;
    //cout << myArray[i] << endl;
  }
  totalSort(n);
}

/**
 * [Sorting::readFile reads an input file]
 * @param nameF [name of the file]
 */
void Sorting::readFile(string nameF)
{
  string line;
  ifstream fs;
  int n;
  fs.open(nameF);

  if (fs.is_open())
  {
    getline(fs,line);
    n = stoi(line);
    //cout << n << endl;

    arrMerge = new float[n];
    //myArrayB = new float[n];
    arrBubble = new float[n];
    arrSelection = new float[n];
    arrInsertion = new float[n];
    arrQuick = new float[n];

    for (int i = 0; i < n; i++)
    {
      getline(fs,line);
      //cout << "here" << endl;
      //fs >> arrBubble[i];
      arrMerge[i] = stof(line);
      // // cout << "here" << endl;
      //myArrayB[i] = stof(line);
      // //cout << "here" << endl;
      arrBubble[i] = stof(line);
      // //cout << arrBubble[i] << endl;
      arrSelection[i] = stof(line);
      // //cout << "here" << endl;
      arrInsertion[i] = stof(line);
      // //cout << "here" << endl;
      arrQuick[i] = stof(line);
      // // cout << "here" << endl;

    }
    fs.close();
  }
  totalSort(n);
}

/**
 * [Sorting::print method to display the array]
 * @param myArr [array of floats]
 */
void Sorting::print(float *myArr)
{
  for (int i = 0; i < 100; i++)
  {
    cout << myArr[i] << endl;
  }
}

/**
 * [Sorting::partition helper method for quicksort]
 * @param  myArr [float array]
 * @param  left  [pivot for left array]
 * @param  right [pivot for right array]
 * @return       [description]
 */
int Sorting::partition(float *myArr, int left, int right)
{
  int pivot = myArr[right];
  int pivLeft = left - 1;
  float tmp;

  for(int i = left; i <= right-1; ++i)
  {
    if(myArr[i] <= pivot)
    {
      pivLeft++;
      tmp = myArr[pivLeft];
      myArr[pivLeft] = myArr[i];
      myArr[i] = tmp;
    }
  }
  tmp = myArr[pivLeft+1];
  myArr[pivLeft+1] = myArr[right];
  myArr[right] = tmp;
  return (pivLeft+1);
}

/**
 * [Sorting::quickSort algorithm]
 * @param myArr [array of floats]
 * @param left  [pivot]
 * @param right [pivot]
 */

void Sorting::quickSort(float *myArr, int left, int right)
{
  int pivot;
  if(left < right)
  {
    pivot = partition(myArr, left, right);

    quickSort(myArr, left, pivot-1);
    quickSort(myArr, pivot+1, right);
  }
}
/**
 * [Sorting::merge helper function for mergeSort]
 * @param myArr [array of floats]
 * @param l     [left]
 * @param m     [right]
 * @param r     [middle]
 */

void Sorting::merge(float *myArr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    float left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = myArr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = myArr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (j < n2 && i < n1)
    {
        if (left[i] <= right[j])
        {
            myArr[k] = left[i];
            i++;
        }
        else
        {
            myArr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        myArr[k] = left[i];
        i++;
        k++;
    }
    {
        myArr[k] = right[j];
        j++;
        k++;
    }
}

/**
 * [Sorting::mergeSort algorithm]
 * @param myArr [array of floats]
 * @param start [start of array]
 * @param end   [end of array]
 */

void Sorting::mergeSort(float *myArr, int start, int end)
{
  int middle;
  if (start < end)
  {
      middle = start + ( end - start)/2;
      mergeSort(myArr, start, middle);
      mergeSort(myArr, middle + 1, end);
      merge(myArr, start, middle, end);
  }
}

/**
 * [Sorting::exportSorted creates files to export the results]
 * @param n [input]
 */
void Sorting::exportSorted(int n)
{
  ofstream ofsBubble;
  ofstream ofsInsertion;
  ofstream ofsSelection;
  ofstream ofsQuick;
  ofstream ofsMerge;

  ofsBubble.open("TestBubbleResults.txt");
  ofsInsertion.open("TestInsertionResults.txt");
  ofsSelection.open("TestSelectionResults.txt");
  ofsQuick.open("TestQuickResults.txt");
  ofsMerge.open("TestMergeResults.txt");

  for (int i = 0; i < n; i ++)
  {
    ofsBubble << arrBubble[i] << endl;
    ofsInsertion << arrInsertion[i] << endl;
    ofsSelection << arrSelection[i] << endl;
    ofsQuick << arrQuick[i] << endl;
    ofsMerge << arrMerge[i] << endl;
  }
  ofsBubble.close();
  ofsInsertion.close();
  ofsSelection.close();
  ofsQuick.close();
}


/**
 * [Sorting::totalSort prints time for each algorithm]
 * @param n [description]
 */
void Sorting::totalSort(int n)
{
  float *arrTotal = new float[4];
  clock_t start, end;
  float totalTime,totalTime1, totalTime2, totalTime3, totalTime4;
  string answer;
  start = clock();
  bubbleSort(arrBubble, n-1);
  double best, worst;
  //print(arrBubble);
  end = clock();
  totalTime = ((double) (end - start)) / CLOCKS_PER_SEC;;
  cout << "BubbleSort: " << totalTime << " seconds to execute." << endl;
  arrTotal[0] = totalTime;


  start = clock();
  insertionSort(arrInsertion, n-1);
  //print(arrInsertion);
  end = clock();
  totalTime1 = ((double) (end - start)) / CLOCKS_PER_SEC;;
  cout << "insertionSort: " << totalTime1 << " seconds to execute." << endl;
  arrTotal[1] = totalTime1;


  start = clock();
  selectionSort(arrSelection, n-1);
  end = clock();
  totalTime2 = ((double) (end - start)) / CLOCKS_PER_SEC;;
  cout << "selectionSort: " << totalTime2 << " seconds to execute." << endl;
  arrTotal[2] = totalTime2;


  start = clock();
  quickSort(arrQuick, 0, n-1);
  end = clock();
  totalTime3 = ((double) (end - start)) / CLOCKS_PER_SEC;;
  cout << "quickSort: " << totalTime3 << " seconds to execute." << endl;
  arrTotal[3] = totalTime3;


  start = clock();
  mergeSort(arrMerge, 0, n-1);
  end = clock();
  totalTime4 = ((double) (end - start)) / CLOCKS_PER_SEC;;
  cout << "mergeSort: " << totalTime4 << " seconds to execute." << endl;
  arrTotal[4] = totalTime4;

  bubbleSort(arrTotal, 5);
  best = arrTotal[0];
  worst = arrTotal[4];

  cout << "The fastest algorithm time was: " << "\x1b[32m" << best << "\x1B[0m" << " seconds to execute" <<endl;
  cout << "The slowest algorithm time was: " << "\x1b[31m" << worst << "\x1B[0m" << " seconds to execute" << endl;


  cout << "Would you like to get the results exported? (Yes/No)" << endl;
  cin >> answer;
  if (answer == "Yes" || "Yes" || "yes")
  {
    exportSorted(n);

  }
  else
    return;
  cout << "Thanks for waiting, choose what you want to do next. " << endl;
  cout << endl;
}


/**
 * [Sorting::generateRandomList creates a random list of number that will be exported into a file]
 * @param file [name of the file]
 * @param n    [size of the list]
 */
void Sorting::generateRandomList(string file, int n)
{
  ofstream fs;
  float z;
  srand(time(NULL));
  fs.open(file);
  fs << n << endl;
  for (int i = 0; i < n; i++)
  {
    z = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/n));
    fs << z << endl;
  }
  readFile(file);
  //totalSort(n);
}
