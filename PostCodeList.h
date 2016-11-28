#ifndef POSTCODELIST_H
#define POSTCODELIST_H

typedef struct PostCodeNode PostCodeNode;

struct PostCodeNode{
  int postcode;
  PostCodeNode *next;
};

class PostCodeIterator;
class PostCodeList{
 private:
  PostCodeNode *first;
  PostCodeNode *last;
  int size;

 public:
  PostCodeList();
  ~PostCodeList();
  bool empty();
  bool exists(int postcode);
  void add(int postcode);
  void remove(int postcode);
  PostCodeNode* getFirst();
  PostCodeIterator* iterator();
};

class PostCodeIterator{
 private:
  PostCodeNode *currNode;
  PostCodeNode *firstNode;

 public:
  PostCodeIterator(PostCodeList& postCodeList);
  ~PostCodeIterator();
  bool hasNext();
  int next();
};

#endif
