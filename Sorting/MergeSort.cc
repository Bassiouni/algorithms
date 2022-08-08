#include <iostream>

void merge(int *arr, uint32_t begin, uint32_t mid, uint32_t end)
{
  const uint32_t sizeOfIArr = mid - begin + 1;
  const uint32_t sizeOfJArr = end - mid;

  auto *iArray = new int[sizeOfIArr];
  auto *jArray = new int[sizeOfJArr];

  for (uint32_t i = 0; i < sizeOfIArr; i++)
    iArray[i] = arr[begin + i];

  for (uint32_t j = 0; j < sizeOfJArr; j++)
    jArray[j] = arr[mid + 1 + j];

  uint32_t i, j, k = begin;
  i = j = 0;

  while (true)
  {
    if (iArray[i] <= jArray[j])
    {
      arr[k++] = iArray[i];
      i++;
    }
    else
    {
      arr[k++] = jArray[j];
      j++;
    }

    if (i == sizeOfIArr)
    {
      for (int x = j; x < sizeOfJArr; x++)
      {
        arr[k++] = jArray[x];
      }
      break;
    }

    if (j == sizeOfJArr)
    {
      for (int x = i; x < sizeOfIArr; x++)
      {
        arr[k++] = iArray[x];
      }
      break;
    }
  }

  delete[] iArray;
  delete[] jArray;
}

void mergeSort(int *arr, uint32_t begin, uint32_t end)
{
  if (end <= begin)
    return;

  uint32_t mid = begin + (end - begin) / 2;

  mergeSort(arr, begin, mid);
  mergeSort(arr, mid + 1, end);
  merge(arr, begin, mid, end);
}

int main()
{
  int arr[] = {3, 1, 7, 2, 4, 5};

  mergeSort(arr, 0, 5);

  for (int &elm : arr)
  {
    std::cout << elm << ' ';
  }
  std::cout << std::endl;
}
