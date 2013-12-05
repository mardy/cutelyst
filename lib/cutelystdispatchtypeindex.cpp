/*
 * Copyright (C) 2013 Daniel Nicoletti <dantti12@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "cutelystdispatchtypeindex.h"
#include "context.h"
#include "cutelystrequest.h"
#include "cutelystaction.h"

#include <QStringBuilder>

CutelystDispatchTypeIndex::CutelystDispatchTypeIndex(QObject *parent) :
    CutelystDispatchType(parent)
{
}

bool CutelystDispatchTypeIndex::match(Context *ctx, const QString &path) const
{
    if (!ctx->req()->args().isEmpty()) {
        return false;
    }

    QList<CutelystAction *> actions = ctx->getActions(QLatin1String("dispatchIndex"), ctx->req()->path());
    if (actions.size()) {
        CutelystAction *action = actions.last();
        setupMatchedAction(ctx, action, QString());

        return true;
    }
    return false;
}

QString CutelystDispatchTypeIndex::uriForAction(CutelystAction *action, const QStringList &captures) const
{
    if (captures.isEmpty()) {
        return QString();
    }

    return QLatin1Char('/') % action->ns();
}

bool CutelystDispatchTypeIndex::isLowPrecedence() const
{
    return true;
}
