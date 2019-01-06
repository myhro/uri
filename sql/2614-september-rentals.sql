SELECT customers.name, rentals.rentals_date
    FROM rentals
    INNER JOIN customers ON (rentals.id_customers = customers.id)
    WHERE to_char(rentals.rentals_date, 'MM') = '09';
