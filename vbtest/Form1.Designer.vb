<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意: 以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改它。
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.GapCal = New System.Windows.Forms.Button()
        Me.TextGapw = New System.Windows.Forms.TextBox()
        Me.TextGapr = New System.Windows.Forms.TextBox()
        Me.TextGapl = New System.Windows.Forms.TextBox()
        Me.TextGapx = New System.Windows.Forms.TextBox()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.Btn_Authorized = New System.Windows.Forms.Button()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'GapCal
        '
        Me.GapCal.Location = New System.Drawing.Point(491, 30)
        Me.GapCal.Name = "GapCal"
        Me.GapCal.Size = New System.Drawing.Size(75, 23)
        Me.GapCal.TabIndex = 0
        Me.GapCal.Text = "间隙计算"
        Me.GapCal.UseVisualStyleBackColor = True
        '
        'TextGapw
        '
        Me.TextGapw.Location = New System.Drawing.Point(40, 30)
        Me.TextGapw.Name = "TextGapw"
        Me.TextGapw.Size = New System.Drawing.Size(65, 21)
        Me.TextGapw.TabIndex = 1
        '
        'TextGapr
        '
        Me.TextGapr.Location = New System.Drawing.Point(387, 30)
        Me.TextGapr.Name = "TextGapr"
        Me.TextGapr.Size = New System.Drawing.Size(65, 21)
        Me.TextGapr.TabIndex = 2
        '
        'TextGapl
        '
        Me.TextGapl.Location = New System.Drawing.Point(276, 30)
        Me.TextGapl.Name = "TextGapl"
        Me.TextGapl.Size = New System.Drawing.Size(65, 21)
        Me.TextGapl.TabIndex = 3
        '
        'TextGapx
        '
        Me.TextGapx.Location = New System.Drawing.Point(150, 30)
        Me.TextGapx.Name = "TextGapx"
        Me.TextGapx.Size = New System.Drawing.Size(65, 21)
        Me.TextGapx.TabIndex = 4
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(38, 9)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(11, 12)
        Me.Label1.TabIndex = 5
        Me.Label1.Text = "W"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Location = New System.Drawing.Point(148, 9)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(11, 12)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "X"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Location = New System.Drawing.Point(274, 9)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(11, 12)
        Me.Label3.TabIndex = 7
        Me.Label3.Text = "L"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Location = New System.Drawing.Point(385, 9)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(11, 12)
        Me.Label4.TabIndex = 8
        Me.Label4.Text = "R"
        '
        'Btn_Authorized
        '
        Me.Btn_Authorized.Location = New System.Drawing.Point(30, 94)
        Me.Btn_Authorized.Name = "Btn_Authorized"
        Me.Btn_Authorized.Size = New System.Drawing.Size(75, 23)
        Me.Btn_Authorized.TabIndex = 9
        Me.Btn_Authorized.Text = "验证授权"
        Me.Btn_Authorized.UseVisualStyleBackColor = True
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(211, 93)
        Me.Button1.Name = "Button1"
        Me.Button1.Size = New System.Drawing.Size(75, 23)
        Me.Button1.TabIndex = 10
        Me.Button1.Text = "生成授权文件"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(598, 261)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Btn_Authorized)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.TextGapx)
        Me.Controls.Add(Me.TextGapl)
        Me.Controls.Add(Me.TextGapr)
        Me.Controls.Add(Me.TextGapw)
        Me.Controls.Add(Me.GapCal)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents GapCal As System.Windows.Forms.Button
    Friend WithEvents TextGapw As System.Windows.Forms.TextBox
    Friend WithEvents TextGapr As System.Windows.Forms.TextBox
    Friend WithEvents TextGapl As System.Windows.Forms.TextBox
    Friend WithEvents TextGapx As System.Windows.Forms.TextBox
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Btn_Authorized As System.Windows.Forms.Button
    Friend WithEvents Button1 As System.Windows.Forms.Button

End Class
