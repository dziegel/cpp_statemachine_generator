package generator;

import java.util.Collection;

import org.eclipse.epsilon.eol.exceptions.EolUserException;
import org.eclipse.epsilon.eol.userinput.IUserInput;

public class UserInput implements IUserInput {

	@Override
	public void inform(String message) {
		System.out.println(message);
	}

	@Override
	public boolean confirm(String question, boolean default_) throws EolUserException {
		return false;
	}

	@Override
	public Object chooseMany(String question, Collection<?> choices, Collection<?> default_) {
		return null;
	}

	@Override
	public Object choose(String question, Collection<?> choices, Object default_) {
		return null;
	}

	@Override
	public String prompt(String question, String default_) {
		return "";
	}

	@Override
	public int promptInteger(String question, int default_) {
		return 0;
	}

	@Override
	public float promptReal(String question, float default_) {
		return 0;
	}

	@Override
	public double promptReal(String question, double default_) {
		return 0;
	}
}
