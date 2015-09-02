Imports System.Runtime.InteropServices
Public Class Form1
    <DllImport("E:\github\TunnelManage\TunnelManage\Debug\TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GapCalculate(ByVal w As Int32, ByVal x As Int32, ByVal l As Single, ByVal r As Single, ByVal resultStr As String) As Int32


    End Function
    <DllImport("E:\github\TunnelManage\TunnelManage\Debug\TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function Authorized() As Int32

        'a 已经授权过的文件 c:\windows\system32\yzyyzy.txt
        'b 机器码文件 c:\shield\monitor\machin_coad.txt
        'c 经过授权的文件 c:\shield\monitor\soft_data\ver_id.txt


    End Function
    <DllImport("E:\github\TunnelManage\TunnelManage\Debug\TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function CreateKey(ByVal a As String, ByVal b As String) As Int32

    End Function
    Private Sub GapCal_Click(sender As Object, e As EventArgs) Handles GapCal.Click
        Dim resultStr As String
        resultStr = Space(128)
        Dim charNum = GapCalculate(TextGapw.Text(), TextGapx.Text(), TextGapl.Text(), TextGapr.Text, resultStr)
        resultStr = Microsoft.VisualBasic.Left(resultStr, charNum)
        Dim d As Int32
        Dim x As Int32
        Dim strList = resultStr.Split(",")
        d = Convert.ToInt32(strList(0))
        x = Convert.ToInt32(strList(1))
        MessageBox.Show("d is " + strList(0) + "; x is " + strList(1))

    End Sub

 
    Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Btn_Authorized.Click
        Dim result = Authorized()
        MessageBox.Show(result)
    End Sub

    Private Sub Button1_Click_1(sender As Object, e As EventArgs) Handles Button1.Click
        Dim result = CreateKey("c:\shield\monitor\soft_data\ver_id.txt", "c:\shield\monitor\machin_coad.txt")
    End Sub
End Class
