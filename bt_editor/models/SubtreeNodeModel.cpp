#include "SubtreeNodeModel.hpp"
#include <QLineEdit>
#include <QVBoxLayout>

SubtreeNodeModel::SubtreeNodeModel(const QString &subtree_ID,
                                   const ParameterWidgetCreators& creators):
    BehaviorTreeDataModel ("SubTree", subtree_ID, creators )
{
    _line_edit_name->setReadOnly(true);

    auto vlayout = dynamic_cast<QVBoxLayout*>(_main_widget->layout());

    _expand_button = new QPushButton("Expand", _main_widget );
    vlayout->addWidget(_expand_button);

    _expand_button->setStyleSheet("color: black; background-color: white; border: 1px orange;");
    _expand_button->setFlat(false);
    _expand_button->setFocusPolicy(Qt::NoFocus);

    connect( _expand_button, &QPushButton::clicked,
             this, &SubtreeNodeModel::expandButtonPushed );

    updateNodeSize();
}

SubtreeExpandedNodeModel::SubtreeExpandedNodeModel(
        const QString &subtree_ID,
        const ParameterWidgetCreators& creators):
    BehaviorTreeDataModel ("SubTree", subtree_ID, creators )
{
    _line_edit_name->setReadOnly(true);

    auto vlayout = dynamic_cast<QVBoxLayout*>(_main_widget->layout());

    _collapse_button = new QPushButton("Collapse", _main_widget );
    vlayout->addWidget(_collapse_button);

    _collapse_button->setStyleSheet("color: black; background-color: white; border: 1px orange;");
    _collapse_button->setFlat(false);
    _collapse_button->setFocusPolicy(Qt::NoFocus);

    connect( _collapse_button, &QPushButton::clicked,
             this, &SubtreeExpandedNodeModel::collapseButtonPushed );

    updateNodeSize();
}



