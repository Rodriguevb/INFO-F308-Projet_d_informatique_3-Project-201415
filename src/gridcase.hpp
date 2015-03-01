#ifndef GRIDCASE_H
#define GRIDCASE_H


class GridCase
{
public:
    GridCase();
    GridCase(bool lighted, bool free);
    ~GridCase();

    bool isLighted();
    bool isFree();

    void setLighted(bool lighted);
    void setFree(bool free);

private:
    bool m_lighted;
    bool m_free;
};

#endif // GRIDCASE_H
