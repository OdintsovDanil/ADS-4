// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
	int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = (1 + i); j < len; j++) {
			if ((arr[i] + arr[j]) == value) {
				count++;
			}
		}
	}
	return count;
}
int countPairs2(int *arr, int len, int value) {
	int end = 0;
	for (int x = 0; x < len ; x++) {
		if (arr[x] >= value) {
			end = x;
			break;
		}
	}
	int count = 0, j = len - 1;
	for (int i = 0; i < j; i++) {
		for (int right = len - 1; i < right; right--) {
			if ((arr[i] + arr[right]) == value) {
				count++;
			}
		}
	}
	return count;
}
int countPairs3(int *arr, int len, int value) {
	int end = 0;
	for (int x = 0; x < len; x++) {
		if (arr[x] >= value) {
			end = x;
			break;
		}
	}
	int count = 0;
	for (int i = 0; i < len; i++) {
		int left = i + 1, right = len - 1, mid = 0;
		bool find = false;
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] == value - arr[i]) {
				count++;
				find = true;
				break;
			}
			if (arr[mid] < value - arr[i]) {
				left = mid + 1;
			}
			if (arr[mid] > value - arr[i]) {
				right = mid - 1;
			}
		}
		int frontleft = mid, frontright = frontleft;
		if (find == true) {
			while (arr[frontleft - 1] == arr[mid] && frontleft - 1 != i) {
				count++;
				frontleft--;
			}
			while (arr[frontright + 1] == arr[mid]) {
				count++;
				frontright++;
			}
		}
	}
	return count;
}
