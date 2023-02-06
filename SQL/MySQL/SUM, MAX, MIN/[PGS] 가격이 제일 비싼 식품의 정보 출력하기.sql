-- LV2
SELECT *
FROM FOOD_PRODUCT
WHERE PRICE = (
    SELECT MAX(PRICE) AS PRICE
    FROM FOOD_PRODUCT
)
ORDER BY PRICE DESC