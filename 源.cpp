#include<iostream>

using namespace std;

void MergeSort(int array[],int start,int end);

void Merge(int array[],int start,int end,int mid);

int main()
{
	int array[] = { 4,23,342,2341,43,54,564,442,3423,4545,245,46,464,6,4,32,542 };
	int end = sizeof(array) / sizeof(array[0]);
	MergeSort(array, 0, end-1);
	for (auto c : array)
		cout << c << endl;
	system("pause");
	return 0;
}

void MergeSort(int array[], int start, int end)
{
	if (start == end)
		return;
	int n = (start + end) / 2;
	MergeSort(array, start, n);
	MergeSort(array, n+1, end);
	Merge(array, start, end, n);
}

void Merge(int array[], int start, int end, int mid)
{
	int *temp;
	temp = new int[end - start + 1];
	int i = start, j = mid + 1, k = 0;
	while (i != mid + 1 && j != end + 1)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	if (i == mid + 1)
		while (j != end + 1)
			temp[k++] = array[j++];
	if (j == end + 1)
		while (i != mid + 1)
			temp[k++] = array[i++];
	for (int t = 0; t <= end - start; t++)
		array[t + start] = temp[t];

}