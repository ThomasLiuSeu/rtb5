/*!
 * Ext JS Library 3.4.0
 * Copyright(c) 2006-2011 Sencha Inc.
 * licensing@sencha.com
 * http://www.sencha.com/license
 */
Ext.onReady(function() {
    Ext.QuickTips.init();

    var baseUrl = "http://www.rtb5.com/cgi-bin/admin_cgi?";
    // NOTE: This is an example showing simple state management. During development,
    // it is generally best to disable state management as dynamically-generated ids
    // can change across page loads, leading to unpredictable results.  The developer
    // should ensure that stable state ids are set for stateful components in real apps.    
    Ext.state.Manager.setProvider(new Ext.state.CookieProvider());


    //  Ext.Ajax.request({
    //     url: 'http://www.rtb5.com/cgi-bin/admin_cgi?action=query&object=union',
    //     headers: {
    //         'userHeader': 'userMsg'
    //     },
    //     params: { a: 10, b: 20 },
    //     method: 'GET',
    //     success: function (response, options) {
    //         Ext.MessageBox.alert('成功', '从服务端获取结果: ' + response.responseText);
    //     },
    //     failure: function (response, options) {
    //         Ext.MessageBox.alert('失败', '请求超时或网络故障,错误编号：' + response.status);
    //     }
    // });

    var unionStore = new Ext.data.Store({
        proxy: new Ext.data.HttpProxy({
            url: '/cgi-bin/admin_cgi?action=query&object=union'
            // url: 'http://www.rtb5.com/table.php?table=union'
        }),
        reader: new Ext.data.JsonReader({
            totalProperty: 'total',
            root: 'unions',
            // id: 0,\
            fields: [{
                name: 'union_id'
            },
            {
                name: 'union_name'
            },
            {
                name: 'url_pattern'
            },
            {
                name: 'union_ext'
            }]
        })
    });


    var cm = new Ext.grid.ColumnModel([
        new Ext.grid.CheckboxSelectionModel(), 
    {
        id: 'union_id',
        header: 'Union Id',
        width: "100%",
        anchor: '98%',
        sortable: true,
        dataIndex: 'union_id'
    },
    {
        header: 'Union Name',
        width: "100%",
        sortable: true,
        dataIndex: 'union_name'
    },
    {
        header: 'Url Pattern',
        width: "100%",
        sortable: true,
        dataIndex: 'url_pattern'
    },
    {
        header: 'Union Ext',
        width: "100%",
        sortable: true,
        dataIndex: 'union_ext'
    }])
    // create the Grid
    var grid = new Ext.grid.GridPanel({
        store: unionStore,
        tbar: [{
            xtype: 'button',
            text: '添加',
            iconCls: 'icon-add',
            handler: addUnion
        },
        {
            xtype: 'button',
            text: '删除',
            iconCls: 'icon-add',
            handler: function() {}
        },
        {
            xtype: 'button',
            text: '修改',
            iconCls: 'icon-add',
            handler: function() {}
        }],
        cm: cm,
        viewConfig: {
            forceFit: true
        },
        stripeRows: true,
        height: 800,
        width: '100%',
        title: 'Union Grid',
        // config options for stateful behavior
        stateful: true,
        stateId: 'grid'
    });

    var editorform = new Ext.form.FormPanel({
        labelWidth: 100,
        labelAlign: 'right',
        frame: true,
        autoWidth: true,
        height: 240,
        width: 375,
        buttonAlign: 'center',
        items: [{
            id: 'union_id',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Union Id',
            name: "union_id"
        },{
            id: 'union_name',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Union Name',
            name: "union_name"
        },
        {
            id: 'url_pattern',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Url Pattern',
            name: "url_pattern"
        },{
            id: 'percent',
            xtype: 'textfield',
            width: 150,
            fieldLabel: 'Percent',
            name: "percent"
        }]
    });
    var addWindow = new Ext.Window({
        title: 'Add Union',
        width: 400,
        resizable: false,
        closeAction: 'hide',
        autoHeight: true,
        constrainHeader: true,
        modal: true,
        plain: true,
        items: [{
            layout: 'form',
            items: editorform
        }],
        buttons: [{
            text: '确定',
            handler: function() {
                var baseUrl = "http://www.rtb5.com/cgi-bin/admin_cgi?";
                var union_id = Ext.getCmp("union_id");
                var union_name = Ext.getCmp("union_name");
                var url_pattern = Ext.getCmp("url_pattern");
                var percent = Ext.getCmp("percent");
                var requestUrl;
                requestUrl = baseUrl + "action=add&object=union" + "&" + union_id.getId() + "=" + union_id.getValue()
                                + "&" + union_name.getId() + "=" + union_name.getValue()
                                + "&" + url_pattern.getId() + "=" + url_pattern.getValue()
                                + "&" + percent.getId() + "=" + percent.getValue();
                Ext.Ajax.request({
                    url : requestUrl,
                    method : "POST",
                    success : function (res) {
                        if (res.responseText.trim() && 
                            JSON.parse(res.responseText.trim())
                            && JSON.parse(res.responseText.trim()).status === "1") {
                            Ext.Msg.alert("Message", "Success");
                        } else {
                            Ext.Msg.alert("Message", "Error");
                        }
                        addWindow.hide();
                    }
                })
            }
        },
        {
            text: '取消',
            handler: function() {
                addWindow.hide();
            }
        }]
    });

    function addUnion() {
        addWindow.show();
    };

        unionStore.load();

    // render the grid to the specified div in the page
    grid.render('grid-example');
});