SELECT products.name, categories.name
    FROM products
    INNER JOIN categories ON (products.id_categories = categories.id)
    WHERE amount > 100 AND id_categories IN (1, 2, 3, 6, 9);
