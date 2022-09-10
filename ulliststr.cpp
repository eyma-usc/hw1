#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

std::string const & ULListStr::front() const
{
  Item *headItem = head_;

  return headItem->val[headItem->first];
}
std::string const & ULListStr::back() const
{
  Item *tailItem = tail_;

  return tailItem->val[tailItem->last-1];
}


void ULListStr::push_front(const std::string& val)
{
  Item* headItem = head_;
  // Scenario 3, empty node, place at back
  if(empty())
  {
    //1. Create item
    Item *firstItem = new Item();
    //2. Set head, tail, front, and last
    head_ = firstItem;
    tail_ = firstItem;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;

    // 3. Insert element at back of new list
    head_->val[head_->first] = val;
  }

  // Scenario 1, there is space before the insert
  else if(headItem->first != 0)
  {
    // 1. Move first index back
    headItem->first = headItem->first-1;
    // 2. Insert element at front
    headItem->val[headItem->first] = val;
  }

  // Scenario 2, no space in front, make new node 
  else if(headItem->first == 0)
  {
    Item *nextItem = new Item();
    headItem->prev = nextItem;
    nextItem->next = headItem;
    //2. Set head, tail, front, and last
    headItem = nextItem;
    nextItem->first = ARRSIZE-1;
    nextItem->last = ARRSIZE;
    head_ = nextItem;

    // 3. Insert element at back of new list
    nextItem->val[nextItem->first] = val;
  }
  ++size_;
}

void ULListStr::push_back(const std::string& val)
{
  // Scenario 3, empty node, place at front
  Item* tailItem = tail_;
  if(empty()) 
  {
    //1. Create item
    Item *firstItem = new Item();
    //2. Set head, tail, front, and last
    head_ = firstItem;
    tail_ = firstItem;
    firstItem->first = 0;
    firstItem->last = 1;
    // 3. Insert element at back of new list
    firstItem->val[firstItem->first] = val;  
  }
  // Scenario 1, there is space after the insert
  else if(tailItem->last != ARRSIZE)
  {
    tailItem->val[tailItem->last] = val;
    // 1. Insert element at back
    tailItem->last = tailItem->last+1;

    
  }
  // Scenario 2, no space behind, make new node 
  else if(tailItem->last == 10)
  {
    Item *nextItem = new Item();
    tailItem->next = nextItem;
    nextItem->prev = tailItem;
    //2. Set head, tail, front, and last
    tail_ = nextItem;
    nextItem->first = 0;
    nextItem->last = 1;

    // 3. Insert element at back of new list
    nextItem->val[nextItem->first] = val;
  }
  ++size_;
}


void ULListStr::pop_back()
{
  if (size_ == 0) 
  {
    //empty
    return; 
  }
  if (size_ == 1)
  {
    delete tail_;
    delete head_;
    tail_ = nullptr;
    head_ = nullptr;
  }
  // item has one remaining
  else if(tail_->last == 1) 
  {
    Item *temp = tail_->prev;
    delete tail_;
    tail_ = temp;
  }
  // still has multiple things remaining
  else  
  { 
    tail_->last--;
  }
  size_--;
}

void ULListStr::pop_front()
{
  // empty
  if (empty()) 
  {
    return; 
  }

  //list has one
  if (size_ == 1) 
  {
    //Item* newHead = head_;
    delete head_;
    delete tail_;
    tail_ = nullptr;
    head_ = nullptr;
  }
  //item has one
  else if(head_->first == ARRSIZE-1)
  {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  //multiple
  else 
  { 
    head_->first++;
  }
  size_--;
}



std::string* ULListStr::getValAtLoc(size_t loc) const
{
  Item* newItem = head_;
  size_t loc_r = 0;
  size_t temp = newItem->first;

  if(loc < 0 || loc >= size())
  {
    return nullptr;
  }
  while(loc_r != loc)
  {
    loc_r++;
    temp++;    
    if(temp == newItem->last)
    {
      newItem = newItem->next;
      temp = 0;
    }
  }
  return &newItem->val[temp];
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
