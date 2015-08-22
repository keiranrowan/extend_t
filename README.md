# extend_t
extend_t is a set of dynamic types for C

## Array

```C
{
  // Create an Array with Items of Template Type
  array_t v;
  int template;
  array_init(&v, &template);
  
  // -- Manipulative Operations --
  
  // Append Item to the Array
  array_append(&v, 314);
  
  // Set Value at Index
  array_set(&v, 0, 313);
  
  // Retrieve Array Value Safely
  array_get(&v, 0);
  
  // Remove an Array Element
  array_remove(&v, 0);
  
  // -- Informational Operations --
  
  // Get Length of Array in terms of Items
  array_length(&v);
  
  // Get Type of Array
  array_type(&v);
  
  // Delete the Array
  array_free(&v);
}
```

## List

```C
{
  // Create a List
  list_t l;
  list_init(&l);
  
  // -- Manipulative Operations --
  
  // Append an Item to the List
  list_append(&l, "Hello World");
  
  // Set Value at Index in the List
  list_set(&l, 0, 3.14);
  
  // Get Item Value at Index Safely
  list_get(&l, 0);
  
  // Remove an Array Element
  list_remove(&l, 0);
  
  // -- Informational Operations --
  
  // Get Length of List in terms of Items
  list_length(&v);
  
  // Get Type of Array
  list_type(&v);
  
  // Delete the Array
  list_free(&v);
}
```
