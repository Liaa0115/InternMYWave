SELECT 
    department,
    AVG(salary) AS average_salary
FROM 
    employees
GROUP BY 
    department;



WITH DepartmentSalaries AS (
    SELECT 
        department,
        MAX(salary) AS highest_salary
    FROM 
        employees
    GROUP BY 
        department
)



SELECT 
    e.department,
    ds.highest_salary,
    e.name
FROM 
    DepartmentSalaries ds
JOIN 
    employees e ON ds.department = e.department AND ds.highest_salary = e.salary;