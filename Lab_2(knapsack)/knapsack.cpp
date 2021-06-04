#include <stdio.h>

struct Item {
  char id[5];
  int weight;
  int value;
  float density;
};

void fk(Item items[], int n, int W);

void fk(Item items[], int n, int W) {
  int i, wt;
  float value;

  float totalWeight = 0, totalBenefit = 0;

  for(i = 0; i < n; i++) {
    if(items[i].weight + totalWeight <= W) {

      totalWeight += items[i].weight;
      totalBenefit += (items[i].weight);

      printf("Selected Item: %s\tWeight: %d\tValue: %d\tTotal Weight: %f\tTotal Benefit: %f\n", items[i].id, items[i].weight, items[i].value, totalWeight, totalBenefit);

    } else {
      wt = (W - totalWeight);
      value = wt * (float(items[i].value) / items[i].weight);

      totalWeight += wt;
      totalBenefit += value;

      printf("Selected Item: %s\tWeight: %d\tValue: %f\tTotal Weight: %f\tTotal Benefit: %f\n", items[i].id, wt, value, totalWeight, totalBenefit);

      break;
    }
  }

  printf("Total Weight: %f\n", totalWeight);
  printf("Total Benefit: %f\n", totalBenefit);
}

int main(void) {
  //variables
  int i, j;

  //list items
  Item items[4] = {
    {"w1",  5, 800, 0},
    {"w2", 2, 900, 0},
    {"w3",  7, 400, 0},
    {"w4",  7, 500, 0},
  };
  //{ { 5, 800 }, { 2, 900 }, { 7, 400 }, { 7, 500 } };

  //temp item
  Item temp;

  //number of items
  int n = 4;

  //max weight limit of knapsack
  int W =8;

  //compute desity = (value/weight)
  for(i = 0; i < n; i++) {
    items[i].density = float(items[i].value) / items[i].weight;
  }

  //sort by density in descending order
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(items[j+1].density > items[j].density) {
        temp = items[j+1];
        items[j+1] = items[j];
        items[j] = temp;
      }
    }
  }

  fk(items, n, W);

  return 0;
}
