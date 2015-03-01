#include "gridcase.hpp"

GridCase::GridCase() :
    m_lighted(false),
    m_free(true)
{

}

GridCase::GridCase(bool lighted, bool free) :
    m_lighted(lighted),
    m_free(free)
{

}

GridCase::~GridCase()
{

}

bool GridCase::isLighted() {
    return m_lighted;
}

bool GridCase::isFree() {
    return m_free;
}

void GridCase::setLighted(bool lighted) {
    m_lighted = lighted;
}

void GridCase::setFree(bool free) {
    m_free = free;
}
