module Point()
    option object;    
    local x, y;
end module
bezierInterpolate := proc(arr, t)
    local newPts := [];
    for i from 1 to nops(arr)-1 do
        local newX := arr[i + 1].x - arr[i].x;
        newX := newX * t + arr[i].x;
        local newY := arr[i + 1].y - arr[i].y;
        newY := newY * t + arr[i].y;
        local newPt := object(Point);
        newPt.x := newX;
        newPt.y := newY;
        newPts := [op(newPts), newPt];
    end do;
    if nops(newPts) = 1 then
        return newPts[1];
    else
        return bezierInterpolate(newPts, t);
    end if;

end proc;

bezierCurve := proc(arr, inc)
    local pts := [];
    for i from 0 to 1 by inc do
        pts := [op(pts), bezierInterpolate(arr, i)];
    end do;
    pts := [op(pts), arr[nops(arr)]];
    return pts;
end proc;
