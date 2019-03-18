#include <stdio.h>
#include <string.h>
typedef struct {
  char street[50];
  char city[50];
} Address;
typedef struct {
  int id;
  char name[20];
  char title[20];
  Address address;
} Employee;
int main() {
  Employee emp = {1000, "John Smith", "Developer",{"123 Main Street", "Chicago"}};
  printf("Emp Id: %d \n", emp.id);
  printf("Name: %s \n", emp.name);
  printf("Title: %s \nAddress:\n", emp.title);
  printf("Street: %s\n", emp.address.street);
  printf("City: %s\n", emp.address.city);
  return 0;
}
