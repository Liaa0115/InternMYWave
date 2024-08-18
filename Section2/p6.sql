SELECT 
    name,
    position
FROM 
    employees
WHERE 
    salary > 50000;


SELECT 
    name,
    position,
    salary
FROM 
    employees
ORDER BY 
    salary DESC
LIMIT 3;