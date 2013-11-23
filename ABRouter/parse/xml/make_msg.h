#ifndef MAKE_MSG_H
#define MAKE_MSG_H

typedef struct str_t
{
  size_t len;
  unsigned char *data;
}str_t;

#define get_key(x) x.key.data
#define get_value(x) x.value.data

typedef struct 
{
  str_t key;
  str_t value;
}key_value;


typedef struct list_node
{
  key_value node;
  struct list_node *next;
  struct list_node *child;
}list_node ;
#endif
