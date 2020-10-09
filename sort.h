#define Num 200000
int insertion_sort(int, int*);
int selection_sort(int, int*);
int quick_sort(int, int, int*);
int merge_sort(int, int, int*);
int partition(int, int, int*);
int swap(int*, int*);
int temp[Num];

int partition(int left, int right, int* table){
	int pivot, i, j;
	pivot = table[left];
	i = left + 1;
	j = right;
	while (i <= j){
		while (i <= right && table[i] < pivot){
			i++;
		}
		while (table[j] > pivot){
			j--;
		}
		if (i <= j){
			swap(&table[i], &table[j]);
			i++;
			j--;
		}
	}
	swap(&table[left], &table[j]);
	return j;
}

int quick_sort(int first, int last, int* table){
	int j;
	if (first < last){
		j = partition(first, last, table);
		quick_sort(first, j - 1, table);
		quick_sort(j + 1, last, table);
	}
	return 0;
}

int merge_sort(int first, int last, int *list){
	int middle, i, j, k;
	if (first < last){
		middle = (first + last) / 2;
		merge_sort(first, middle, list);
		merge_sort(middle + 1, last, list);
		for (i = first; i <= middle; i++){
			temp[i] = list[i];
		}
		for (j = middle + 1; j <= last; j++){
			temp[middle + 1 + last - j] = list[j];
		}
		i = first;
		j = last;
		for (k = first; k <= last; k++){
			if (temp[i] <= temp[j]){
				list[k] = temp[i];
				i++;
			} else {
				list[k] = temp[j];
				j--;
			}
		}
	}
	return 0;
}

int selection_sort(int n, int *a){
	int i, j, min;
	for (i = 0; i < n - 1; i++){
		min = i;
		for (j = i + 1; j < n; j++){
			if (a[j] < a[min]){
				min = j;
			}
		}
		swap(&a[i], &a[min]);
	}
	return 0;
}

int insertion_sort(int n, int *a){
  int i, j;
  for(i = 1; i <= n - 1; i++){
    j = i;
    while(a[j - 1] > a[j] && j > 0){
      swap(&a[j - 1], &a[j]);
      j--;
    }
  }
  return 0;
}

int swap(int* x, int* y){
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	return 0;
}
