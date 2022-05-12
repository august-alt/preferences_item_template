/***********************************************************************************************************************
**
** Copyright (C) 2021 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#ifndef MVVM_FOLDERS_{{cookiecutter.item_name|upper}}_WIDGET_H
#define MVVM_FOLDERS_{{cookiecutter.item_name|upper}}_WIDGET_H

#include "interfaces/preferenceswidgetinterface.h"

#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class {{cookiecutter.item_name}}Widget; }
QT_END_NAMESPACE

class QDataWidgetMapper;

namespace ModelView
{
    class ViewModel;
    class ViewModelDelegate;
    class SessionItem;
}

namespace mvvm_folders
{

class {{cookiecutter.item_name}}Item;

//! {{cookiecutter.item_name}} representation for editor.

class {{cookiecutter.item_name}}Widget : public PreferenceWidgetInterface
{
public:
    Q_OBJECT

public:
    explicit {{cookiecutter.item_name}}Widget(QWidget* parent = nullptr, {{cookiecutter.item_name}}Item* item = nullptr);
    ~{{cookiecutter.item_name}}Widget() override;

    void setItem(ModelView::SessionItem *item) override;

    bool validate() override;

public slots:
    void submit() override;

private slots:
    void on_actionComboBox_currentIndexChanged(int index);

private:
    {{cookiecutter.item_name}}Widget(const {{cookiecutter.item_name}}Widget&)            = delete;   // copy ctor
    {{cookiecutter.item_name}}Widget({{cookiecutter.item_name}}Widget&&)                 = delete;   // move ctor
    {{cookiecutter.item_name}}Widget& operator=(const {{cookiecutter.item_name}}Widget&) = delete;   // copy assignment
    {{cookiecutter.item_name}}Widget& operator=({{cookiecutter.item_name}}Widget&&)      = delete;   // move assignment

private:
    //!< Underlying item of this view.
    {{cookiecutter.item_name}}Item* m_item {nullptr};

    std::unique_ptr<ModelView::ViewModel> view_model;
    std::unique_ptr<ModelView::ViewModelDelegate> delegate;
    std::unique_ptr<QDataWidgetMapper> mapper;

private:
    Ui::{{cookiecutter.item_name}}Widget *ui {nullptr};
};

}

#endif//MVVM_FOLDERS_{{cookiecutter.item_name|upper}}_WIDGET_H

