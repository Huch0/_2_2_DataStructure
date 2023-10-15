#ifndef TREE_H
#define TREE_H

#include "../Array/Array.h"

template <typename T>
class TreeNode {
private:
    T data_;
    TreeNode<T>* parent_;
    Array<TreeNode<T>*> children_;
public:
    TreeNode(const T& data) : data_(data), parent_(nullptr), children_() {};
    ~TreeNode() {};
    // Get data of TreeNode
    const T& getData() const {
        return data_;
    }
    // Set data of TreeNode
    void setData(T& data) {
        data_ = data;
    }
    // Get parent of this position
    TreeNode<T>* parent() const {
        return parent_;
    }
    // Get list of children of this position
    Array<TreeNode<T>> children() const {
        return children_;
    }
    // Add child to children list
    void addChild(TreeNode<T>* newChild) {
        children_.push(newChild);
    }
    // Check is this position root
    bool isRoot() const {
        return parent_ == nullptr;
    }
    // Check is this position external
    bool isExternal() const {
        return children_.isEmpty();
    }
};

template <typename T>
class
#endif // TREE_H
