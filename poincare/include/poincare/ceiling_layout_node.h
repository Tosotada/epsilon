#ifndef POINCARE_CEILING_LAYOUT_NODE_H
#define POINCARE_CEILING_LAYOUT_NODE_H

#include <poincare/bracket_pair_layout_node.h>
#include <poincare/layout_engine.h>

namespace Poincare {

class CeilingLayoutNode : public BracketPairLayoutNode {
public:
  using BracketPairLayoutNode::BracketPairLayoutNode;
  int writeTextInBuffer(char * buffer, int bufferSize, PrintFloat::Mode floatDisplayMode, int numberOfSignificantDigits) const override {
    return LayoutEngine::writePrefixSerializableRefTextInBuffer(SerializableRef(const_cast<CeilingLayoutNode *>(this)), buffer, bufferSize, floatDisplayMode, numberOfSignificantDigits, "ceil");
  }
  // TreeNode
  size_t size() const override { return sizeof(CeilingLayoutNode); }
#if TREE_LOG
  const char * description() const override { return "CeilingLayout"; }
#endif

protected:
  bool renderBottomBar() const override { return false; }
};

class CeilingLayoutRef : public LayoutReference<CeilingLayoutNode> {
public:
  CeilingLayoutRef(TreeNode * n) : LayoutReference<CeilingLayoutNode>(n) {}
  CeilingLayoutRef(LayoutRef l) : LayoutReference<CeilingLayoutNode>() {
    addChildTreeAtIndex(l, 0);
  }
};

}

#endif