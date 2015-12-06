Ext.onReady(function() {
    Ext.QuickTips.init();

    var baseUrl = "http://www.rtb5.com/cgi-bin/admin_cgi?";
    // NOTE: This is an example showing simple state management. During development,
    // it is generally best to disable state management as dynamically-generated ids
    // can change across page loads, leading to unpredictable results.  The developer
    // should ensure that stable state ids are set for stateful components in real apps.    
    Ext.state.Manager.setProvider(new Ext.state.CookieProvider());


    var campaignStore = new Ext.data.Store({
        proxy: new Ext.data.HttpProxy({
            url: '/cgi-bin/admin_cgi?action=query&object=campaign'
        }),
        reader: new Ext.data.JsonReader({
            totalProperty: 'total',
            root: 'campaigns',
            id: 0,
            fields: [{
                name: 'campaign_id'
            },
            {
                name: 'campaign_name'
            },
            {
                name: 'pattern'
            },
            {
                name: 'union_id'
            }]
        })
    });
    campaignStore.load();

    var sm1 = new Ext.grid.CheckboxSelectionModel({
            singleSelect : false
        });
    var cm = new Ext.grid.ColumnModel([
       sm1, 
    {
        id: 'campaign_id',
        header: 'Campaign Id',
        width: "100%",
        anchor: '98%',
        sortable: true,
        dataIndex: 'campaign_id',
        editor : new Ext.form.TextField({
            readOnly : false
        })
    },
    {
        header: 'Campaign Name',
        width: "100%",
        sortable: true,
        dataIndex: 'campaign_name',
        editor : new Ext.form.TextField({
            readOnly : false
        })
    },
    {
        header: 'Pattern',
        width: "100%",
        sortable: true,
        dataIndex: 'pattern',
        editor : new Ext.form.TextField({
            readOnly : false
        })
    },
    {
        header: 'Union Id',
        width: "100%",
        sortable: true,
        dataIndex: 'union_id',
        editor : new Ext.form.TextField({
            readOnly : false
        })
    }])
    // create the Grid
    var grid = new Ext.grid.GridPanel({
        id : "mainGrid",
        store: campaignStore,
        sm : sm1,
        disableSelection : true,
        // clicksToEdit : 2, 
        tbar: [{
            xtype: 'button',
            text: '添加',
            iconCls: 'icon-add',
            handler: addCampaign
        },
        {
            xtype: 'button',
            text: '删除',
            iconCls: 'x-dd-drop-ok-add',
            handler: function() {}
        },
        {
            xtype: 'button',
            text: '修改',
            iconCls: 'btn-edit',
            handler: editCampaign
        }],
        cm: cm,
        viewConfig: {
            forceFit: true
        },
        stripeRows: true,
        height: 800,
        width: '100%',
        title: 'Campagin Grid',
        // config options for stateful behavior
        stateful: true,
        stateId: 'grid'
    });


    var addWindowForm = new Ext.form.FormPanel({
        labelWidth: 100,
        labelAlign: 'right',
        frame: true,
        autoWidth: true,
        height: 240,
        width: 375,
        buttonAlign: 'center',
        items: [{
            id: 'campaign_id_add',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Campaign Id',
            name: "campaign_id"
        },{
            id: 'campaign_name_add',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Campaign Name',
            name: "campaign_name"
        },
        {
            id: 'pattern_add',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Pattern',
            name: "pattern"
        },{
            id: 'union_id_add',
            xtype: 'textfield',
            width: 150,
            fieldLabel: 'Union Id',
            name: "union_id"
        }]
    });

    var addWindow = new Ext.Window({
        title: 'Add Campaign',
        width: 400,
        resizable: false,
        closeAction: 'hide',
        autoHeight: true,
        constrainHeader: true,
        modal: true,
        plain: true,
        items: [{
            layout: 'form',
            items: addWindowForm
        }],
        buttons: [{
            text: '确定',
            handler: function() {
                var baseUrl = "http://www.rtb5.com/cgi-bin/admin_cgi?";
                var union_id = Ext.getCmp("union_id_add");
                var campaign_id = Ext.getCmp("campaign_id_add");
                var campaign_name = Ext.getCmp("campaign_name_add");
                var pattern = Ext.getCmp("pattern_add");
                var requestUrl;
                requestUrl = baseUrl + "action=add&object=campaign" + "&" + "union_id" + "=" + union_id.getValue()
                                + "&" + "campaign_id" + "=" + campaign_id.getValue()
                                + "&" + "campaign_name" + "=" + campaign_name.getValue()
                                + "&" + "pattern" + "=" + pattern.getValue();
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

    function addCampaign() {
        addWindow.show();
    };

        var editWindowForm = new Ext.form.FormPanel({
        labelWidth: 100,
        labelAlign: 'right',
        frame: true,
        autoWidth: true,
        height: 240,
        width: 375,
        buttonAlign: 'center',
        items: [{
            id: 'campaign_id',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Campaign Id',
            name: "campaign_id"
        },{
            id: 'campaign_name',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Campaign Name',
            name: "campaign_name"
        },
        {
            id: 'pattern',
            xtype: 'textfield',
            allowBlank : false,
            width: 150,
            fieldLabel: 'Pattern',
            name: "pattern"
        },{
            id: 'union_id',
            xtype: 'textfield',
            width: 150,
            fieldLabel: 'Union Id',
            name: "union_id"
        }]
    });

    var editWindow = new Ext.Window({
        title: 'Edit Campaign',
        width: 400,
        resizable: false,
        closeAction: 'hide',
        autoHeight: true,
        constrainHeader: true,
        modal: true,
        plain: true,
        items: [{
            layout: 'form',
            items: editWindowForm
        }],
        buttons: [{
            text: '确定',
            handler: function() {
                var baseUrl = "http://www.rtb5.com/cgi-bin/admin_cgi?";
                var union_id = Ext.getCmp("union_id");
                var campaign_id = Ext.getCmp("campaign_id");
                var campaign_name = Ext.getCmp("campaign_name");
                var pattern = Ext.getCmp("pattern");
                var requestUrl;
                requestUrl = baseUrl + "action=update&object=campaign" + "&" + union_id.getId() + "=" + union_id.getValue()
                                + "&" + campaign_id.getId() + "=" + campaign_id.getValue()
                                + "&" + campaign_name.getId() + "=" + campaign_name.getValue()
                                + "&" + pattern.getId() + "=" + pattern.getValue();
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
                editWindow.hide();
            }
        }]
    });

    function editCampaign(e) {
        editWindow.show();
        var mainGrid = Ext.getCmp("mainGrid");
        var selectedData = mainGrid.getSelectionModel().getSelected().data;
        Ext.getCmp("campaign_id").setValue(selectedData.campaign_id);
        Ext.getCmp("campaign_name").setValue(selectedData.campaign_name);
        Ext.getCmp("pattern").setValue(selectedData.pattern);
        Ext.getCmp("union_id").setValue(selectedData.union_id);
        Ext.getCmp("campaign_id").setDisabled(true);
    };





    // render the grid to the specified div in the page
    grid.render('grid-example');
});