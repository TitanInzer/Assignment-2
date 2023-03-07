#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {   /* Creates the Employee Class */
protected:
    double weeklySalary;    /* Create Elements for Weekly Salary, Health Insurance Contribution, and Vacations Days */
    double healthInsuranceContribution;
    double vacationDays;

public:
    virtual void calculateWeeklySalary() = 0;   /* Sets all Inital Values at One */
    virtual void calculateHealthInsuranceContribution() = 0;
    virtual void calculateVacationDays() = 0;

    double getWeeklySalary() const { return weeklySalary; } 
    double getHealthInsuranceContribution() const { return healthInsuranceContribution; }
    double getVacationDays() const { return vacationDays; }
};

class Professional : public Employee {  /* Creates the Professional Employee Class */
private:
    double monthlySalary;  /* Professionals are Paid Monthly */
    int vacationDaysPerMonth; /* Given Days in a Month */

public:
    Professional(double salary, int daysPerMonth) : monthlySalary(salary), vacationDaysPerMonth(daysPerMonth) {}

    void calculateWeeklySalary() override {
        weeklySalary = monthlySalary / 4; /* To Find the Weekly Salary divide Monthly Salary by Four */
    }

    void calculateHealthInsuranceContribution() override {  /* Health Insurance Contribution is set to be 10% of Monthly Salary */
        healthInsuranceContribution = monthlySalary * 0.1;
    }

    void calculateVacationDays() override {      /* Get a Set Number of Vacation Days, Given an Amount per month divided by 12 */
        vacationDays = vacationDaysPerMonth / 12;
    }
};

class Nonprofessional : public Employee {  /* Creates the Nonprofessional Employee Class */
private:
    double hourlyRate;  /* Rate of Pay */
    double vacationHoursPerHour;  /* Factor of how Vaction Hrs are Earned */ 

public:
    Nonprofessional(double rate, double hoursPerHour) : hourlyRate(rate), vacationHoursPerHour(hoursPerHour) {}

    void calculateWeeklySalary() override {
        weeklySalary = hourlyRate * 40;    /* Presumes a 40hr Work Week, hrs multiplied by pay rate is the Weekly Salary */
    }

    void calculateHealthInsuranceContribution() override {
        healthInsuranceContribution = weeklySalary * 0.05;  /* Health Insurance Contribution is 5% of the Weekly Salary */
    }

    void calculateVacationDays() override {
        vacationDays = weeklySalary / 1000 * vacationHoursPerHour;  /* Given an amount based on Weekly Salary and Credited based on hrs */
    }
};

#endif
