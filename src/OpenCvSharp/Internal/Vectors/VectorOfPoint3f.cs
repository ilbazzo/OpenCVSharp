﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using OpenCvSharp.Internal.Util;

namespace OpenCvSharp.Internal.Vectors;

/// <summary> 
/// </summary>
// ReSharper disable once InconsistentNaming
public class VectorOfPoint3f : DisposableCvObject, IStdVector<Point3f>
{
    /// <summary>
    /// Constructor
    /// </summary>
    public VectorOfPoint3f()
    {
        ptr = NativeMethods.vector_Point3f_new1();
    }

    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="size"></param>
    public VectorOfPoint3f(nuint size)
    {
        if (size < 0)
            throw new ArgumentOutOfRangeException(nameof(size));
        ptr = NativeMethods.vector_Point3f_new2(size);
    }

    /// <summary>
    /// Constructor
    /// </summary>
    /// <param name="data"></param>
    public VectorOfPoint3f(IEnumerable<Point3f> data)
    {
        if (data is null)
            throw new ArgumentNullException(nameof(data));
        var array = data.ToArray();
        ptr = NativeMethods.vector_Point3f_new3(array, (nuint)array.Length);
    }

    /// <summary>
    /// Releases unmanaged resources
    /// </summary>
    protected override void DisposeUnmanaged()
    {
        NativeMethods.vector_Point3f_delete(ptr);
        base.DisposeUnmanaged();
    }

    /// <summary>
    /// vector.size()
    /// </summary>
    public int Size
    {
        get
        {
            var res = NativeMethods.vector_Point3f_getSize(ptr);
            GC.KeepAlive(this);
            return (int)res;
        }
    }

    /// <summary>
    /// &amp;vector[0]
    /// </summary>
    public IntPtr ElemPtr
    {
        get
        {
            var res = NativeMethods.vector_Point3f_getPointer(ptr);
            GC.KeepAlive(this);
            return res;
        }
    }

    /// <summary>
    /// Converts std::vector to managed array
    /// </summary>
    /// <returns></returns>
    public Point3f[] ToArray()
    {
        var size = Size;
        if (size == 0)
        {
            return Array.Empty<Point3f>();
        }
        var dst = new Point3f[size];
        using (var dstPtr = new ArrayAddress1<Point3f>(dst))
        {
            long bytesToCopy = Marshal.SizeOf<Point3f>() * dst.Length;
            unsafe
            {
                Buffer.MemoryCopy(ElemPtr.ToPointer(), dstPtr.Pointer.ToPointer(), bytesToCopy, bytesToCopy);
            }
        }
        GC.KeepAlive(this); // ElemPtr is IntPtr to memory held by this object, so
        // make sure we are not disposed until finished with copy.
        return dst;
    }
}
