Imports System.Runtime.InteropServices
Public Class Form1
    <DllImport("d:\Users\kai.xu.CN1\Desktop\TunnelManage\TunnelManage\Debug\TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GapCalculate(ByVal w As Int32, ByVal x As Int32, ByVal l As Int32, ByVal r As Int32, ByVal resultStr As String) As Int32


    End Function
    <DllImport("E:\github\TunnelManage\TunnelManage\Debug\TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function Authorized(ByVal a As String, ByVal b As String, ByVal c As String) As Int32

    End Function
    <DllImport("E:\github\TunnelManage\TunnelManage\Debug\TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function CreateKey(ByVal a As String, ByVal b As String) As Int32

    End Function
    Private Sub GapCal_Click(sender As Object, e As EventArgs) Handles GapCal.Click
        Dim resultStr As String
        resultStr = Space(60)
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
        Dim result = Authorized("c:\1.txt", "c:\2.txt", "c:\3.txt")
        MessageBox.Show(result)
    End Sub

    Private Sub Button1_Click_1(sender As Object, e As EventArgs) Handles Button1.Click
        Dim result = CreateKey("c:\3.txt", "c:\2.txt")
    End Sub
End Class
