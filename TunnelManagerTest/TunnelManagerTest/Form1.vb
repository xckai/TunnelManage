Imports System.Runtime.InteropServices

Public Class Form1
    <DllImport("TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function GapCalculate(ByVal w As Int32, ByVal x As Int32, ByVal l As Single, ByVal r As Single, ByVal resultStr As String) As Int32


    End Function
    <DllImport("TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function Authorized() As Int32




    End Function
    <DllImport("TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function CreateKey(ByVal a As String, ByVal b As String) As Int32

    End Function
    <DllImport("TunnelManage.dll", CharSet:=CharSet.Unicode, SetLastError:=True, BestFitMapping:=False, CallingConvention:=CallingConvention.Cdecl)> Public Shared Function RingCalculate(ByVal n As Int32, ByVal w As Int32, ByVal dr As Int32, ByVal lxj As Int32, ByVal l0 As Int32, ByVal l1 As Int32, ByVal l2 As Int32, ByVal l3 As Int32, ByVal l4 As Int32, ByVal l5 As Int32, ByVal resultStr As String) As Int32

    End Function

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        Dim result = Authorized()
        MessageBox.Show(result)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Dim result = CreateKey("c:\shield\monitor\soft_data\ver_id.txt", "c:\shield\monitor\machin_coad.txt")
    End Sub
End Class
