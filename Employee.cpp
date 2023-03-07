#include <iostream>
#include "Employee.h"

int main() {
    Professional prof(5000, 20);  /* Test of Professional Employees Class */
    prof.calculateWeeklySalary();
    prof.calculateHealthInsuranceContribution();
    prof.calculateVacationDays();
    std::cout << "Professional Employee\nWeekly Salary: " << prof.getWeeklySalary() << "\nHealth Insurance Contribution: " << prof.getHealthInsuranceContribution() << "\nVacation Days: " << prof.getVacationDays() << std::endl;

    Nonprofessional nonprof(15, 0.1);  /* Test of Nonprofessional Employees Class */
    nonprof.calculateWeeklySalary();
    nonprof.calculateHealthInsuranceContribution();
    nonprof.calculateVacationDays();
    std::cout << "\nNon-Professional Employee\nWeekly Salary: " << nonprof.getWeeklySalary() << "\nHealth Insurance Contribution: " << nonprof.getHealthInsuranceContribution() << "\nVacation Days: " << nonprof.getVacationDays() << std::endl;

    return 0;
}
