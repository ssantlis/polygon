
#include <iostream>
#include <vector>

using namespace std;

int sumaVseh(vector<int> vec) {
  int sum=0;
  for (int num : vec) {
    sum += num;
  }
  return sum;
}
// 5 5 1 11  {5}   {0} //4   //22  0
bool findMyEqualPodVectors(vector<int>& podVector1, vector<int>& podVector2, vector<int> vec, int index,int sum1, int sum2) //index    sum1   sum2
{

  if (index == vec.size()) //как только дошли до конца
  {
    return sum1 == sum2;  //Проверка равны ли две суммы    sum1-сумма первого подвектора  sum2 - сумма второго подвектора // {5 5 1}   // {11}
  }


  podVector1.push_back(vec[index]);// добавить в конец
  if (findMyEqualPodVectors(podVector1, podVector2, vec, index + 1, sum1 + vec[index], sum2)) // 11     ind = {3}    sum1+=5 //sum22
  {
    return true;
  }
  podVector1.pop_back();// удалить из конца

  
  podVector2.push_back(vec[index]); // добавить в конец
  if (findMyEqualPodVectors(podVector1, podVector2, vec, index + 1, sum1, sum2 + vec[index]) ) //4
  {
    return true;
  }
  podVector2.pop_back(); // удалить из конца 

  return false;
}



int main()
{
  vector<int> chisla = { };

  int totalSum = sumaVseh(chisla);

  cout << totalSum;


  //assert
  if (totalSum % 2 != 0) {
    
    cout << "Нельзя выполнить задачу";
    return 0; 
  }


  vector <int> podVector1{}, podVector2{}; // 5 5 1    11
  if (findMyEqualPodVectors(podVector1, podVector2, chisla,0,0,0) )
  {

    for (int num : podVector1) {
      cout << num << " ";
    }
    cout << endl;
    for (int num : podVector2) {
      cout << num << " ";
    }
  }
  else {
    cout << "Нельзя раздеить по условию";
  }

  
}
