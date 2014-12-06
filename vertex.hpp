#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <QGraphicsEllipseItem>
#include <QString>
#include <QColor>
#include <QSet>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

class Edge;

class Vertex : public QGraphicsEllipseItem
{
public:
    Vertex();
    ~Vertex();

    void setText(const QString &name);
    QString getName() const;
    void setTextColor(const QColor &color);
    QColor textColor() const;
    void setOutlineColor(const QColor &color);
    QColor outlineColor() const;
    void setBackgroundColor(const QColor &color);
    QColor backgroundColor() const;

    void addEdge(Edge* e);
    void removeEdge(Edge* e);




private:
    QString m_name;
    QSet<Edge *> myEdges;
    QColor myTextColor;
    QColor myBackgroundColor;
    QColor myOutlineColor;

signals:

public slots:

};

#endif // VERTEX_HPP
