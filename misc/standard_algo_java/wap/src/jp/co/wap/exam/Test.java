package jp.co.wap.exam;

import java.util.Arrays;
import java.util.List;

import jp.co.wap.exam.lib.Interval;

public class Test {

	public void testProblem1Usage() {
	Problem1 p = new Problem1();
	// example: Figure 1
	
	Interval interval1 = new Interval("08:00", "12:00");
	Interval interval2 = new Interval("06:00", "09:00");
	Interval interval3 = new Interval("11:00", "13:30");
	List<Interval> figure1 = Arrays.asList(interval1, interval2, interval3);
	System.out.println(p.getMaxIntervalOverlapCount(figure1));
	// example: Figure 2

	List<Interval> figure2 = Arrays.asList(new Interval("09:00", "12:30"),
	new Interval("06:00", "09:30"), new Interval("12:00", "14:30"),
	new Interval("10:00", "10:30"), new Interval("11:00", "13:30"));
	System.out.println(p.getMaxIntervalOverlapCount(figure2));
	}
	
}
